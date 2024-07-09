using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CarController : MonoBehaviour
{
    public float Sensitivity;
    public AudioSource CarSound;

    private float speed = 0;
    Vector2 startPos;

    private void Start()
    {
        Application.targetFrameRate = 60;
    }

    private void Update()
    {
        if (Input.GetMouseButtonDown(0))
            this.startPos = Input.mousePosition;

        else if (Input.GetMouseButtonUp(0))
        {
            Vector2 endPos = Input.mousePosition;
            float swipeLength = endPos.x - startPos.x;

            this.speed = swipeLength / Sensitivity;
            CarSound.Play();
        }
        transform.Translate(this.speed, 0, 0);
        this.speed *= 0.98f;
    }
}
