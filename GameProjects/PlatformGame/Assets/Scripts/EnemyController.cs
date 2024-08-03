using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    [SerializeField] private Rigidbody enemyRb;
    [SerializeField] private float walkSpeed;
    [SerializeField] private float checkGroundOffset;
    int facingDir = -1;

    void Start()
    {

    }

    void FixedUpdate()
    {
        if (GameDirector.instance.CheckGround(transform, checkGroundOffset, facingDir))
            enemyRb.MovePosition(transform.position + transform.right * facingDir * Time.deltaTime * walkSpeed);
        else
            facingDir *= -1;
    }
}
