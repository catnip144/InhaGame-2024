using UnityEngine;

public class EnemyStateContext
{
    public IEnemyState CurrentState { get; set; }
    private readonly EnemyController enemyController;
    
    private IEnemyState patrolState = new EnemyPatrolState();
    private IEnemyState stareState = new EnemyStareState();
    private IEnemyState attackState = new EnemyAttackState();
    private IEnemyState chaseState = new EnemyChaseState();

    public EnemyStateContext(EnemyController enemyController)
    {
        this.enemyController = enemyController;
    }

    public void Transition(EnemyState stateType)
    {
        IEnemyState nextState = GetIEnemyState(stateType);

        if (nextState == CurrentState)
            return;
        
        if (CurrentState != null)
            CurrentState.OnStateExit(enemyController);

        CurrentState = nextState;
        enemyController.SetEnemyStateType(stateType);
        CurrentState.OnStateEnter(enemyController);
    }

    private IEnemyState GetIEnemyState(EnemyState stateType)
    {
        switch (stateType)
        {
            case EnemyState.PATROL:
                return patrolState;

            case EnemyState.STARE:
                return stareState;

            case EnemyState.CHASE:
                return chaseState;

            case EnemyState.ATTACK:
                return attackState;
            
            default:
                return patrolState;
        }
    }
}
