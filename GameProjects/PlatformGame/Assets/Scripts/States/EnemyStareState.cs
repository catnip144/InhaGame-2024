using UnityEngine;

public class EnemyStareState : IEnemyState
{
    private EnemyController enemyControl;
    private Transform enemyTransform;
    EnemyChaseState enemyChaseState;

    public void OnStateEnter(EnemyController controller)
    {
        if (enemyControl.PreviousState == EnemyState.PATROL)
        {
            enemyControl.SetStareDelayTimer(enemyControl.StareDelayMaxTime);
            enemyControl.Exclamation.SetActive(true);
        }
    }

    public void OnStateUpdate(EnemyController controller)
    {
        enemyControl.SetStareDelayTimer(enemyControl.StareDelayTimer - Time.deltaTime);

        if (enemyControl.StareDelayTimer > 0)
            return;

        if (enemyChaseState.StartChaseCondition())
        {
            enemyControl.Exclamation.SetActive(false);
            enemyControl.StateContext.Transition(EnemyState.CHASE);
        }
        else if((enemyTransform.position - GameDirector.instance.PlayerPos).magnitude > enemyControl.ChaseStartDistance * 1.5f)
        {
            enemyControl.Exclamation.SetActive(false);
            enemyControl.StateContext.Transition(EnemyState.PATROL);
        }
    }

    public void OnStateExit(EnemyController controller)
    {
    }

    public void Init(EnemyController controller)
    {
        enemyControl    = controller;
        enemyTransform  = controller.transform;
        enemyChaseState = (EnemyChaseState)controller.StateContext.GetIEnemyState(EnemyState.CHASE);
    }
}
