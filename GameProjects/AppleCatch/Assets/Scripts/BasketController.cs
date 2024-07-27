using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BasketController : MonoBehaviour
{
    [SerializeField] private GameDirector gameDirector;
    [SerializeField] private AudioClip appleSE;
    [SerializeField] private AudioClip bombSE;

    private AudioSource aud;
    private Camera mainCamera;
    private RaycastHit rayHit;
    private Ray ray;
    void Start()
    {
        Application.targetFrameRate = 60;
        mainCamera = Camera.main;
        aud = GetComponent<AudioSource>();
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ray = mainCamera.ScreenPointToRay(Input.mousePosition);
            if (Physics.Raycast(ray, out rayHit, Mathf.Infinity))
            {
                float x = Mathf.RoundToInt(rayHit.point.x);
                float z = Mathf.RoundToInt(rayHit.point.z);
                transform.position = new Vector3(x, transform.position.y, z);
            }
        }
    }
    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag != "Item")
            return;

        HandleItem(other.GetComponent<ItemController>());
        Destroy(other.gameObject);
    }

    private void HandleItem(ItemController itemControl)
    {
        ItemType itemType = itemControl.GetItemType();
        //Debug.Log($"¿‚æ“¥Ÿ! {itemType}");

        switch (itemType)
        {
            case ItemType.APPLE:
                gameDirector.GetApple();
                aud.PlayOneShot(appleSE);
                break;

            case ItemType.BOMB:
                gameDirector.GetBomb();
                aud.PlayOneShot(bombSE);
                break;

            default:
                break;
        }
    }
}
