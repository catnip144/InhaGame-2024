using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttackState : IEnemyState
{
    private EnemyController enemyControl;
    private Animator enemyAnim;

    public void OnStateEnter(EnemyController controller)
    {
    }

    public void OnStateUpdate(EnemyController controller)
    {
        if (enemyControl.AttackTimer < 0)
        {
            Debug.Log("플레이어를 공격!");
            enemyAnim.Play("Attack", -1, 0f);
            enemyControl.SetAttackTimer(enemyControl.AttackIntervalTime);
        }
        else
            enemyControl.SetAttackTimer(enemyControl.AttackTimer - Time.deltaTime);
    }

    public void OnStateExit(EnemyController controller)
    {
    }

    public void Init(EnemyController controller)
    {
        enemyControl   = controller;
        enemyAnim      = controller.EnemyAnim;
    }
}
