using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArrowController : MonoBehaviour
{
    public float arrowRadius;
    [SerializeField] private float moveDistance;
    private PlayerController player;
    void Start()
    {
        player = GameManager.instance.Player;
    }
    void Update()
    {
        transform.Translate(0, -moveDistance, 0);

        DetectFloor();
        DetectPlayerCollision();
    }
    private void DetectFloor()
    {
        if (transform.position.y < GameManager.instance.DestroyPosY)
            Destroy(gameObject);
    }
    private void DetectPlayerCollision()
    {
        Vector2 arrowPos = transform.position;
        Vector2 playerPos = player.transform.position;

        float distance = (arrowPos - playerPos).magnitude;
        if (distance < arrowRadius + player.PlayerRadius)
        {
            GameManager.instance.DecreaseHp();
            Destroy(gameObject);
        }
    }

}
