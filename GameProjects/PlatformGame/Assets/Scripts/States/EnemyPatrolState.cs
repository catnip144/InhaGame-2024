using UnityEngine;

public class EnemyPatrolState : IEnemyState
{
    private EnemyController enemyControl;
    private Transform enemyTransform;
    private Rigidbody enemyRb;

    public void OnStateEnter(EnemyController controller)
    {   
    }

    public void OnStateUpdate(EnemyController controller)
    {
        if (GameDirector.instance.CheckGround(enemyTransform, enemyControl.CheckGroundOffset, enemyControl.FacingDir))
            enemyRb.MovePosition(enemyTransform.position + enemyTransform.right * enemyControl.FacingDir * Time.deltaTime * enemyControl.WalkSpeed);
        else
            enemyControl.InvertFacingDir();
        
        LookOut(enemyControl.FacingDir);
    }
    public void OnStateExit(EnemyController controller)
    {
    }

    public void Init(EnemyController controller)
    {
        enemyControl   = controller;
        enemyTransform = controller.transform;
        enemyRb        = controller.EnemyRb;
    }

    private void LookOut(int facingDir)
    {
        Ray forwardRay = new Ray(enemyTransform.position, -Vector3.left * facingDir);
        Debug.DrawRay(enemyTransform.position, -Vector3.left * facingDir * enemyControl.LookOutDistance, Color.red);

        if (Physics.Raycast(forwardRay, enemyControl.LookOutDistance, GameDirector.instance.PlayerLayerMask))
        {
            enemyControl.StateContext.Transition(EnemyState.STARE);
        }
    }
}
