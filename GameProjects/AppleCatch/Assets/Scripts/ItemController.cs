using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemController : MonoBehaviour
{
    [SerializeField] private ItemType itemType;
    private float dropSpeed = 0;

    void Update()
    {
        transform.Translate(0, dropSpeed, 0);
        if (transform.position.y < -1.0f)
        {
            Destroy(gameObject);
        }
    }

    public ItemType GetItemType()
    {
        return itemType;
    }
    public void SetItemDropSpeed(float dropSpeed)
    {
        this.dropSpeed = dropSpeed;
    }
}
public enum ItemType { APPLE, BOMB }