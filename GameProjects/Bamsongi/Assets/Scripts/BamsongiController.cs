using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BamsongiController : MonoBehaviour
{
    [SerializeField] private Rigidbody rb;
    [SerializeField] private ParticleSystem particle;

    private bool hasHitGround = false;
    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "Target")
        {
            rb.isKinematic = true;
            particle.Play();
        }
        else if (!hasHitGround)
        {
            hasHitGround = true;
            rb.AddForce(-rb.velocity.normalized * 800);
        }
    }
    void Update()
    {
        rb.AddForce(-rb.velocity.normalized * 300 * Time.deltaTime);
    }

    public void Shoot(Vector3 dir)
    {
        rb.AddForce(dir);
    }

}
