using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace MatchGame
{
    using System;
    using System.IO;
    using System.Windows.Threading;

    public partial class MainWindow : Window
    {
        DispatcherTimer timer = new DispatcherTimer();
        float currentTime;
        int tenthsOfSecondsElapsed;
        int matchesFound;

        const int MAX_FOOD_TYPE = 8;
        const string scoreDataPath = @"D:\WorkSpace\InhaGame-2024\MatchGame\MatchGame\score\best_score.txt";

        List<string> foodEmoji = new List<string>() {
            "🍕", "🍔", "🍟", "🌭", "🍙",
            "🍛", "🍜", "🍣", "🍤", "🍝",
            "🥪", "🌮", "🌯", "🧀", "🥞"
        };

        public MainWindow()
        {
            InitializeComponent();

            timer.Interval = TimeSpan.FromSeconds(.1);
            timer.Tick += Timer_Tick;
            SetUpGame();
        }

        private void Timer_Tick(object? sender, EventArgs e)
        {
            tenthsOfSecondsElapsed++;
            currentTime = (tenthsOfSecondsElapsed * 0.1f);
            TimeTextBlock.Text = currentTime.ToString("0.0s");

            if (matchesFound == MAX_FOOD_TYPE)
            {
                timer.Stop();
                ShowScore();
            }
        }

        private void SetUpGame()
        {
            Random random = new Random();
            List<string> foodPool = CreateFoodPool(random);

            foreach (TextBlock textBlock in mainGrid.Children.OfType<TextBlock>())
            {
                if (textBlock.Name == "TimeTextBlock")
                    continue;

                textBlock.Visibility = Visibility.Visible;
                int index = random.Next(foodPool.Count);
                string nextemoji = foodPool[index];
                textBlock.Text = nextemoji;
                foodPool.RemoveAt(index);
            }
            timer.Start();
            tenthsOfSecondsElapsed = 0;
            matchesFound = 0;
        }

        private List<string> CreateFoodPool(Random random)
        {
            List<string> foodPool = new List<string>();
            bool[] selected = new bool[foodEmoji.Count];

            while (foodPool.Count < MAX_FOOD_TYPE * 2)
            {
                int index = random.Next(foodEmoji.Count);
                if (selected[index])
                    continue;

                selected[index] = true;
                foodPool.Add(foodEmoji[index]);
                foodPool.Add(foodEmoji[index]);
            }
            return foodPool;
        }

        TextBlock lastTextBlockClicked;
        bool findingMatch = false;

        private void TextBlock_MouseDown(object sender, MouseButtonEventArgs e)
        {
            TextBlock textBlock = sender as TextBlock;
            if (textBlock == null) return;

            if (findingMatch == false)
            {
                textBlock.Visibility = Visibility.Hidden;
                lastTextBlockClicked = textBlock;
                findingMatch = true;
            }
            else if (textBlock.Text == lastTextBlockClicked.Text)
            {
                matchesFound++;
                textBlock.Visibility = Visibility.Hidden;
                findingMatch = false;
            }
            else
            {
                lastTextBlockClicked.Visibility = Visibility.Visible;
                findingMatch = false;
            }
        }

        private void ShowScore()
        {
            float bestTime = -1f;
            using (StreamReader sr = new StreamReader(scoreDataPath))
            {
                string previousScore = sr.ReadLine();
                if (!String.IsNullOrEmpty(previousScore))
                    bestTime = float.Parse(previousScore);
            }
            if (bestTime < 0)
                bestTime = currentTime;

            TimeTextBlock.Text = $"Current: {currentTime.ToString("0.0s")}\nBest: {bestTime.ToString("0.0s")}";

            if (currentTime <= bestTime)
            {
                TimeTextBlock.Text += "\nNew Record!";
                using (StreamWriter wr = new StreamWriter(scoreDataPath))
                    wr.WriteLine(currentTime);
            }
        }

        private void TimeTextBlock_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (matchesFound == MAX_FOOD_TYPE)
                SetUpGame();
        }
    }
}