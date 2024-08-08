using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyChaseState : IEnemyState
{
    private EnemyController enemyControl;
    private Transform enemyTransform;

    public void OnStateEnter(EnemyController controller)
    {
    }

    public void OnStateUpdate(EnemyController controller)
    {
        if (!enemyControl)
            Init(controller);
        
        Vector3 prevPosition = enemyTransform.position;
        Vector3 nextPosition = Vector3.MoveTowards(enemyTransform.position, GameDirector.instance.PlayerPos, Time.deltaTime * enemyControl.ChaseSpeed);

        // 적이 공중에 뜨지 못하게 방지
        nextPosition.y = prevPosition.y;
        nextPosition.z = prevPosition.z;

        bool willMoveLeft = prevPosition.x > nextPosition.x;
        if ((willMoveLeft && enemyControl.FacingDir != -1) || (!willMoveLeft && enemyControl.FacingDir != 1))
            enemyControl.InvertFacingDir();

        if (StopChaseCondition())
        {            
            enemyControl.StateContext.Transition(EnemyState.STARE);
            return;
        }

        enemyTransform.position = nextPosition;
    }

    public void OnStateExit(EnemyController controller)
    {
    }

    private void Init(EnemyController controller)
    {
        enemyControl   = controller;
        enemyTransform = controller.transform;
    }

    private bool StopChaseCondition()
    {
        // 서 있을 플랫폼이 없을 경우
        if (!GameDirector.instance.CheckGround(enemyTransform, enemyControl.CheckGroundOffset, enemyControl.FacingDir))
        {
            return true;
        }
        // 플레이어가 땅에 서 있고, 적이 해당 위치에 닿을 수 없을 경우
        if (GameDirector.instance.PlayerControl.IsGrounded() && Mathf.Abs(GameDirector.instance.PlayerPos.y - enemyTransform.position.y) > 0.5f)
            return true;

        return false;
    }
}
