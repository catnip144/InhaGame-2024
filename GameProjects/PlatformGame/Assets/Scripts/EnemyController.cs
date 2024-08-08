using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    public EnemyStateContext StateContext => enemyStateContext;
    public Rigidbody EnemyRb              => enemyRb;
    public Animator EnemyAnim             => enemyAnim;
    public EnemyState CurrentState        => currentState;
    public EnemyState PreviousState       => previousState;
    public GameObject Exclamation         => exclamation;
    public float LookOutDistance          => lookOutDistance;
    public float CheckGroundOffset        => checkGroundOffset;
    public float WalkSpeed                => walkSpeed;
    public float ChaseSpeed               => chaseSpeed;
    public float AttackTimer              => attackTimer;
    public float AttackIntervalTime       => attackIntervalTime;
    public float StareDelayTimer          => stareDelayTimer;
    public float StareDelayMaxTime        => stareDelayMaxTime;
    public float ChaseStartDistance       => chaseStartDistance;
    public int FacingDir                  => facingDir;

    [SerializeField] private GameObject exclamation;
    [SerializeField] private float walkSpeed, chaseSpeed;
    [SerializeField] private float checkGroundOffset;
    [SerializeField] private float lookOutDistance;
    [SerializeField] private float chaseStartDistance;
    [SerializeField] private EnemyState currentState = EnemyState.PATROL;

    private EnemyStateContext enemyStateContext;
    private EnemyState previousState;
    private Rigidbody enemyRb;
    private Animator enemyAnim;
    private float stareDelayMaxTime = 1f;
    private float stareDelayTimer;
    private float attackIntervalTime = 1f;
    private float attackTimer;
    [SerializeField]private int facingDir = -1;

    void Start()
    {
        enemyRb = GetComponent<Rigidbody>();
        enemyAnim = GetComponent<Animator>();
        enemyStateContext = new EnemyStateContext(this);
        enemyStateContext.Transition(EnemyState.PATROL);
    }

    void FixedUpdate()
    {
        enemyStateContext.CurrentState.OnStateUpdate(this);
    }

    void OnCollisionEnter(Collision collision)
    {
        if (currentState == EnemyState.CHASE && collision.gameObject.tag.Equals("Player"))
        {
            enemyStateContext.Transition(EnemyState.ATTACK);
        }
    }

    void OnCollisionExit(Collision collision)
    {
        if (currentState == EnemyState.ATTACK && collision.gameObject.tag.Equals("Player"))
        {
            enemyStateContext.Transition(EnemyState.CHASE);
        }
    }

    public void InvertFacingDir()
    {
        facingDir *= -1;
    }

    public void SetStareDelayTimer(float time)
    {
        stareDelayTimer = time;
    }

    public void SetAttackTimer(float time)
    {
        attackTimer = time;
    }

    public void SetEnemyStateType(EnemyState stateType)
    {
        previousState = currentState;
        currentState = stateType;
    }
}

public enum EnemyState { PATROL, CHASE, ATTACK, STARE }