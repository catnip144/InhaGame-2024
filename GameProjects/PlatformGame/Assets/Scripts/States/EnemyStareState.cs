using UnityEngine;

public class EnemyStareState : IEnemyState
{
    private EnemyController enemyControl;
    private Transform enemyTransform;
    private Animator enemyAnim;

    public void OnStateEnter(EnemyController controller)
    {
        if (!enemyControl)
            Init(controller);
        
        if (enemyControl.PreviousState == EnemyState.PATROL)
        {
            enemyControl.SetStareDelayTimer(enemyControl.StareDelayMaxTime);
            enemyControl.Exclamation.SetActive(true);
        }
    }

    public void OnStateUpdate(EnemyController controller)
    {
        if (!enemyControl)
            Init(controller);

        enemyControl.SetStareDelayTimer(enemyControl.StareDelayTimer - Time.deltaTime);

        if (enemyControl.StareDelayTimer > 0)
            return;

        if (StartChaseCondition())
        {
            enemyControl.Exclamation.SetActive(false);
            enemyControl.StateContext.Transition(EnemyState.CHASE);
        }
        else if((enemyTransform.position - GameDirector.instance.PlayerPos).magnitude > enemyControl.ChaseStartDistance * 1.5f)
        {
            enemyAnim.Play("Default", -1, 0f);
            enemyControl.Exclamation.SetActive(false);
            enemyControl.StateContext.Transition(EnemyState.PATROL);
        }
    }

    public void OnStateExit(EnemyController controller)
    {
    }

    private void Init(EnemyController controller)
    {
        enemyControl   = controller;
        enemyTransform = controller.transform;
        enemyAnim      = controller.EnemyAnim;
    }

    private bool StartChaseCondition()
    {
        if ((enemyTransform.position - GameDirector.instance.PlayerPos).magnitude >= enemyControl.ChaseStartDistance)
            return false;
        
        if (GameDirector.instance.PlayerControl.IsGrounded() && Mathf.Abs(GameDirector.instance.PlayerPos.y - enemyTransform.position.y) > 0.5f)
            return false;

        return true;
    }
}
