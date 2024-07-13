using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerController : MonoBehaviour
{
    [SerializeField] private Rigidbody2D rb;
    [SerializeField] private Animator animator;
    [SerializeField] private float jumpForce, walkForce, maxWalkSpeed;
    [SerializeField] private float screenEndPos;
    int key = 0;
    void Start()
    {
        Application.targetFrameRate = 60;
    }

    void Update()
    {
        key = 0;

        if (Input.GetKeyDown(KeyCode.Space) && rb.velocity.y == 0)
        {
            rb.AddForce(transform.up * jumpForce);
            animator.SetTrigger("JumpTrigger");
        }

        if (Input.GetKey(KeyCode.LeftArrow)) key = -1;
        else if (Input.GetKey(KeyCode.RightArrow)) key = 1;

        float speedX = Mathf.Abs(rb.velocity.x);

        if (speedX < maxWalkSpeed)
            rb.AddForce(transform.right * key * walkForce);

        if (key != 0)
            transform.localScale = new Vector3(key, 1, 1);

        animator.speed = (rb.velocity.y == 0) ? speedX / 2.0f : 1.0f;

        if (transform.position.y < screenEndPos)
            SceneManager.LoadScene("GameScene");
    }
    void OnTriggerEnter2D(Collider2D collision)
    {
        //Debug.Log("°ñ");
        SceneManager.LoadScene("ClearGame");
    }
}
