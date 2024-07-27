using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class GameDirector : MonoBehaviour
{
    public bool IsGameOver => isGameOver;

    [SerializeField] private ItemGenerator itemGenerator;
    [SerializeField] private TextMeshProUGUI timerTMP, pointTMP;
    [SerializeField] private GameObject gameOver;

    [SerializeField] private float leftTime = 60.0f;
    [SerializeField] private int applePoint;

    [SerializeField] private List<DifficultyInfo> difficulties;

    private int currentPoint = 0;
    private bool isGameOver = false;

    void Update()
    {
        SetGameTimer();
    }

    public void GetApple()
    {
        currentPoint += applePoint;
        UpdatePointText();
    }

    public void GetBomb()
    {
        currentPoint /= 2;
        UpdatePointText();
    }

    public void UpdatePointText()
    {
        pointTMP.text = $"{currentPoint.ToString("F1")} point";
    }

    private void SetGameTimer()
    {
        if (isGameOver) return;
        leftTime -= Time.deltaTime;

        SetGameDifficulty();
        timerTMP.text = leftTime.ToString("F1");
    }

    private void SetGameDifficulty()
    {
        if (leftTime < 0)
        {
            leftTime = 0;
            isGameOver = true;
            gameOver.SetActive(true);
        }
        else if (difficulties.Count > 0 && (leftTime < difficulties[0].OccuranceLeftTime))
        {
            itemGenerator.SetItemSpawnParameter(difficulties[0]);
            difficulties.RemoveAt(0);
        }
    }
}

[System.Serializable]
public class DifficultyInfo
{
    public float OccuranceLeftTime;
    public float Span;
    public float DropSpeed;
    public int BombRatio;
}