using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameStateControl : MonoBehaviour
{
    public static GameStateControl instance = null;
    [SerializeField] private GameState currentGameState;
    private Dictionary<GameState, string> sceneNameDict = new Dictionary<GameState, string>
    {
        { GameState.INTRO,  "IntroScene" },
        { GameState.LOGIN,  "LoginScene" },
        { GameState.LOBBY,  "LobbyScene" },
        { GameState.BATTLE, "BattleScene" },
        { GameState.SHOP,   "ShopScene" },
        { GameState.UPGRADE,"UpgradeScene" },
        { GameState.MYROOM, "MyRoomScene" },
    };
    void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
            Destroy(gameObject);
    }
    public void SetGameState(GameState state)
    {
        currentGameState = state;
        if (state == GameState.EXITGAME)
        {
            ExitGame();
            return;
        }
        SceneManager.LoadScene(sceneNameDict[state]);
    }
    private void ExitGame()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
}
public enum GameState { INTRO, LOGIN, LOBBY, BATTLE, SHOP, UPGRADE, MYROOM, EXITGAME }
