using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RouletteController : MonoBehaviour
{
    public float speed;
    private float rotSpeed;

    void Start()
    {
        Application.targetFrameRate = 60;
        rotSpeed = 0;
    }
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
            this.rotSpeed = speed;

        transform.Rotate(0, 0, this.rotSpeed);
        this.rotSpeed *= 0.96f;
    }
}
