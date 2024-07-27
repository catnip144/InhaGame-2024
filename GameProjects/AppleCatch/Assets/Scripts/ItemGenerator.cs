using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemGenerator : MonoBehaviour
{
    [SerializeField] private GameDirector gameDirector;
    [SerializeField] private GameObject applePrefab, bombPrefab;
    [SerializeField] private int minSpawnX, maxSpawnX, minSpawnZ, maxSpawnZ;
    [SerializeField] private int maxDice;

    private float bombRatio, dropSpeed, span, delta = 0;
    private GameObject spawnedItem;
    
    void Update()
    {
        if (gameDirector.IsGameOver)
            return;

        delta += Time.deltaTime;
        if (delta > span)
        {
            delta = 0;
            RandomSpawn();
        }
    }
    public void SetItemSpawnParameter(DifficultyInfo difficulty)
    {
        span = difficulty.Span;
        dropSpeed = difficulty.DropSpeed;
        bombRatio = difficulty.BombRatio;
    }

    private void RandomSpawn()
    {
        spawnedItem = CreateRandomItem();
        SetItemPos(spawnedItem);
        spawnedItem.GetComponent<ItemController>().SetItemDropSpeed(dropSpeed);
    }

    private GameObject CreateRandomItem()
    {
        int dice = Random.Range(1, maxDice + 1);
        if (dice <= bombRatio)
            return Instantiate(bombPrefab);
        else
            return Instantiate(applePrefab);
    }

    private void SetItemPos(GameObject item)
    {
        float x = Random.Range(minSpawnX, maxSpawnX + 1);
        float z = Random.Range(minSpawnZ, maxSpawnZ + 1);
        item.transform.position = new Vector3(x, item.transform.position.y, z);
    }
}
