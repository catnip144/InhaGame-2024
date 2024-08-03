using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameDirector : MonoBehaviour
{
    int groundLayerMask;
    private static GameDirector _instance = null;
    public static GameDirector instance => _instance;

    void Awake()
    {
        if (_instance == null)
            _instance = this;
    }

    void Start()
    {
        groundLayerMask = 1 << LayerMask.NameToLayer("Ground");
    }

    void Update()
    {
        
    }

    public bool CheckGround(Transform target, float offset, int facingDir)
    {
        RaycastHit hit;
        Vector3 nextPos = new Vector3(target.position.x + offset * facingDir, target.position.y, target.position.z);
        Ray rayTowardsGround = new Ray(nextPos, Vector3.down);

        Debug.DrawRay(nextPos, Vector3.down * 5, Color.green);

        if (Physics.Raycast(rayTowardsGround, out hit, Mathf.Infinity, groundLayerMask))
            return true;

        return false;
    }
}
