using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Ω√¿€");
    }

    // Update is called once per frame
    void Update()
    {
        this.transform.Rotate(new Vector3(1, 1, 1));
    }
}
