using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float PlayerRadius;
    [SerializeField] private float moveDistance;

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.LeftArrow))
            MovePlayer(Direction.LEFT);

        else if (Input.GetKeyDown(KeyCode.RightArrow))
            MovePlayer(Direction.RIGHT);
    }

    private void MovePlayer(Direction dir)
    {
        float moveAmount = moveDistance;

        switch (dir)
        {
            case Direction.LEFT:
                moveAmount *= -1;
                break;

            default:
                break;
        }
        if (transform.position.x + moveAmount < GameManager.instance.MinScreenX)
            return;
        else if (transform.position.x + moveAmount > GameManager.instance.MaxScreenX)
            return;

        transform.Translate(moveAmount, 0, 0);
    }
}
