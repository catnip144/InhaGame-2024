using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class GameCenter : MonoBehaviour
{
    public GameObject car, flag, distance;
    public TextMeshProUGUI distanceText;
    float flagDistance;

    private void Start()
    {
        //this.car = GameObject.Find("car");
        //this.flag = GameObject.Find("flag");
        //this.distance = GameObject.Find("distance");
    }
    private void Update()
    {
        flagDistance = GetFlagDistance();
        ShowFlagDistance();
        DetermineGameOver();
    }
    private float GetFlagDistance()
    {
        return this.flag.transform.position.x - this.car.transform.position.x;
    }
    private void ShowFlagDistance()
    {
        distanceText.text = $"Distance: {flagDistance.ToString("F2")}m";
    }
    private void DetermineGameOver()
    {
        if (flagDistance < 0)
            distanceText.text = "GameOver";
    }
}
