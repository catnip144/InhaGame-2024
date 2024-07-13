using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArrowGenerator : MonoBehaviour
{
    [SerializeField] private GameObject arrowPrefab;
    [SerializeField] private float span, spawnPosY;
    private float delta = 0;

    void Update()
    {
        delta += Time.deltaTime;
        if (delta > span)
        {
            delta = 0;
            GameObject go = Instantiate(arrowPrefab);
            int px = Random.Range((int)GameManager.instance.MinScreenX, (int)GameManager.instance.MaxScreenX);
            go.transform.position = new Vector3(px, spawnPosY, 0);
        }
    }
}
