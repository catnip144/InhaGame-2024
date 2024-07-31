using UnityEngine;

public class ButtonControl : MonoBehaviour
{
    [SerializeField] private GameState changingState;
    public void ChangeGameState()
    {
        GameStateControl.instance.SetGameState(changingState);
    }
}