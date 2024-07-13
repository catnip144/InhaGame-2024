using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public static GameManager instance;
    public PlayerController Player;
    [SerializeField] private Image hpGauge;

    public float MinScreenX, MaxScreenX, DestroyPosY;
    [SerializeField] private float decreaseAmount;
    void Start()
    {
        Application.targetFrameRate = 60;
    }
    void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
    }
    public void DecreaseHp()
    {
        hpGauge.fillAmount -= decreaseAmount;
    }
}
public enum Direction { LEFT, RIGHT };