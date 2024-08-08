using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IEnemyState
{
    void OnStateEnter(EnemyController controller);
    void OnStateUpdate(EnemyController controller);
    void OnStateExit(EnemyController controller);
}
