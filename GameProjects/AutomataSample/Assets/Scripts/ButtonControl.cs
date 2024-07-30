using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ButtonControl : MonoBehaviour
{
    [SerializeField] private GameState changingState;
    public void ChangeGameState()
    {
        GameStateControl.instance.SetGameState(changingState);
    }
}