using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    [SerializeField] private float speed;
    int facingDir = 1;

    void Start()
    {
        
    }

    void Update()
    {
        if (Input.GetKey(KeyCode.LeftArrow))
            facingDir = 1;

        else if (Input.GetKey(KeyCode.RightArrow))
            facingDir = -1;
    }
}
