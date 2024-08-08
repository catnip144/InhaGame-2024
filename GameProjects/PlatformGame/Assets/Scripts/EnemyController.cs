using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    [SerializeField] private GameObject exclamation;
    [SerializeField] private float walkSpeed, chaseSpeed;
    [SerializeField] private float checkGroundOffset;
    [SerializeField] private float lookOutDistance;
    [SerializeField] private float chaseStartDistance;

    private Rigidbody enemyRb;
    private Animator enemyAnim;
    [SerializeField] private EnemyState currentState = EnemyState.PATROL;

    private int facingDir = -1;

    private float stareDelayMaxTime = 1f;
    private float stareDelayTimer;

    private float attackIntervalTime = 1f;
    private float attackTimer;

    void Start()
    {
        enemyRb = GetComponent<Rigidbody>();
        enemyAnim = GetComponent<Animator>();
    }

    void FixedUpdate()
    {
        switch (currentState)
        {
            case EnemyState.PATROL:
                Patrol();
                break;
            
            case EnemyState.CHASE:
                ChasePlayer();
                break;
            
            case EnemyState.ATTACK:
                AttackPlayer();
                break;
            
            case EnemyState.STARE:
                Stare();
                break;
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        if (currentState == EnemyState.CHASE && collision.gameObject.tag.Equals("Player"))
        {
            currentState = EnemyState.ATTACK;
        }
    }
    void OnCollisionExit(Collision collision)
    {
        if (currentState == EnemyState.ATTACK && collision.gameObject.tag.Equals("Player"))
        {
            currentState = EnemyState.CHASE;
        }
    }

    private void Patrol()
    {
        if (GameDirector.instance.CheckGround(transform, checkGroundOffset, facingDir))
            enemyRb.MovePosition(transform.position + transform.right * facingDir * Time.deltaTime * walkSpeed);
        else
        {
            facingDir *= -1;
        }
        LookOut(facingDir);
    }

    private void LookOut(int facingDir)
    {
        Ray forwardRay = new Ray(transform.position, -Vector3.left * facingDir);
        Debug.DrawRay(transform.position, -Vector3.left * facingDir * lookOutDistance, Color.red);

        if (Physics.Raycast(forwardRay, lookOutDistance, GameDirector.instance.PlayerLayerMask))
        {
            if (currentState == EnemyState.PATROL)
            {
                stareDelayTimer = stareDelayMaxTime;
                exclamation.gameObject.SetActive(true);
            }
            currentState = EnemyState.STARE;
        }
    }

    private void ChasePlayer()
    {
        if (StopChaseCondition())
        {
            currentState = EnemyState.STARE;
            return;
        }
        Vector3 prevPosition = transform.position;
        Vector3 nextPosition = Vector3.MoveTowards(transform.position, GameDirector.instance.PlayerPos, Time.deltaTime * chaseSpeed);
        nextPosition.y = prevPosition.y;
        nextPosition.z = prevPosition.z;
        
        transform.position = nextPosition;
    }

    private void AttackPlayer()
    {
        if (attackTimer < 0)
        {
            Debug.Log("플레이어를 공격!");
            enemyAnim.Play("Attack", -1, 0f);
            attackTimer = attackIntervalTime;
        }
        else
        {
            attackTimer -= Time.deltaTime;
        }
    }

    private void Stare()
    {
        stareDelayTimer -= Time.deltaTime;
        if (stareDelayTimer > 0) return;

        if ((transform.position - GameDirector.instance.PlayerPos).magnitude < chaseStartDistance)
        {
            exclamation.gameObject.SetActive(false);
            currentState = EnemyState.CHASE;
        }
        else if((transform.position - GameDirector.instance.PlayerPos).magnitude > chaseStartDistance * 1.5f)
        {
            enemyAnim.Play("Default", -1, 0f);
            exclamation.gameObject.SetActive(false);
            currentState = EnemyState.PATROL;
        }
    }

    private bool StopChaseCondition()
    {
        // 서 있을 플랫폼이 없을 경우
        if (!GameDirector.instance.CheckGround(transform, checkGroundOffset, facingDir))
            return true;
        
        // 플레이어를 닿을 수 없을 경우
        if (GameDirector.instance.PlayerControl.IsGrounded() && Mathf.Abs(GameDirector.instance.PlayerPos.y - transform.position.y) > 0.5f)
            return true;

        return false;
    }
}

public enum EnemyState { PATROL, CHASE, ATTACK, STARE }