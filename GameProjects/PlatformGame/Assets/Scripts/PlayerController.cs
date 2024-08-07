using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    [SerializeField] private Rigidbody playerRb;
    [SerializeField] private float jumpForce;
    [SerializeField] private float walkSpeed;
    int facingDir = 1;

    // Coyote Time : 코요테 타임이란 플레이어가 땅을 밟고 있지 않아도 짧은 순간동안 점프를 가능하게 하는 기법입니다.
    [SerializeField] private float coyoteTime;
    private float coyoteTimer;

    // Jump Buffer : 지면에 착지하기 직전에 점프를 일찍 입력해도 점프가 동작하도록 허용하는 기법입니다.
    [SerializeField] private float jumpBufferTime;
    private float jumpBufferTimer;
    
    void Update()
    {
        if (IsGrounded())
        {
            coyoteTimer = coyoteTime;
        }
        else
            coyoteTimer -= Time.deltaTime;

        if (Input.GetKeyDown(KeyCode.Space))
            jumpBufferTimer = jumpBufferTime;
        else
            jumpBufferTimer -= Time.deltaTime;

        // 유예시간이 남아있을 경우 점프를 허용합니다.
        if (coyoteTimer > 0 && jumpBufferTimer > 0)
        {
            playerRb.AddForce(transform.up * jumpForce);
            jumpBufferTimer = 0f;
        }
        // Short Jump
        if (Input.GetKeyUp(KeyCode.Space) && !IsGrounded())
        {
            playerRb.velocity = new Vector3(playerRb.velocity.x, playerRb.velocity.y * 0.5f, playerRb.velocity.z);

            // 중복 점프를 방지합니다.
            coyoteTimer = 0f;
        }
    }

    void FixedUpdate()
    {
        if (Input.GetKey(KeyCode.RightArrow))
            facingDir = 1;
        else if (Input.GetKey(KeyCode.LeftArrow))
            facingDir = -1;
        else
            facingDir = 0;

        playerRb.MovePosition(transform.position + transform.right * facingDir * Time.deltaTime * walkSpeed);

        if (facingDir != 0)
            transform.localScale = new Vector3(facingDir, 1, 1);
    }

    public bool IsGrounded()
    {
        bool isHit = Physics.Raycast(transform.position, Vector3.down, 1f);
        return isHit && (playerRb.velocity.y == 0);
    }
}
