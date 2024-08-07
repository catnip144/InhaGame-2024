using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameDirector : MonoBehaviour
{
    private static GameDirector _instance = null;
    public static GameDirector instance => _instance;
    public int PlayerLayerMask => playerLayerMask;
    public Vector3 PlayerPos => PlayerControl.transform.position;

    public PlayerController PlayerControl;

    private int playerLayerMask;
    private int groundLayerMask;
    

    void Awake()
    {
        if (_instance == null)
            _instance = this;
    }

    void Start()
    {
        playerLayerMask = 1 << LayerMask.NameToLayer("Player");
        groundLayerMask = 1 << LayerMask.NameToLayer("Ground");
    }

    void Update()
    {
        
    }

    public bool CheckGround(Transform target, float offset, int facingDir)
    {
        Vector3 nextPos = new Vector3(target.position.x + offset * facingDir, target.position.y, target.position.z);
        Ray rayTowardsGround = new Ray(nextPos, Vector3.down);

        Debug.DrawRay(nextPos, Vector3.down * 5, Color.green);

        if (Physics.Raycast(rayTowardsGround, Mathf.Infinity, groundLayerMask))
            return true;

        return false;
    }
}
