using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BamsongiGenerator : MonoBehaviour
{
    [SerializeField] private GameObject bamsongiPrefab;
    [SerializeField] private float throwStrength;
    Camera mainCamera;
    void Start()
    {
        Application.targetFrameRate = 60;
        mainCamera = Camera.main;
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            GameObject bamsongi = Instantiate(bamsongiPrefab);
            Ray ray = mainCamera.ScreenPointToRay(Input.mousePosition);
            Vector3 worldDir = ray.direction;
            bamsongi.GetComponent<BamsongiController>().Shoot(worldDir.normalized * throwStrength);
        }
    }
}
