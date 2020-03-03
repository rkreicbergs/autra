
package lv.autra.autra2.activity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RatingBar;
import android.widget.TextView;
import lv.autra.autra2.R;
import lv.autra.autra2.game.Game;
import lv.autra.autra2.game.Level;

public class ResultScreen extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        Bundle b = getIntent().getExtras();
        int gameType = b.getInt("gameType");
        int levelId = b.getInt("levelId");
        int points = b.getInt("points");
        final Level level = Game.get(gameType).levels[levelId];
        boolean highScore = level.updateScore(points);

        String gameName = getResources().getStringArray(R.array.GameNames)[level.gameType];
        String titleFmt = getResources().getString(R.string.act_level);
        setTitle(String.format(titleFmt, gameName, level.levelId));

        setContentView(R.layout.result_screen);

        TextView pointsView = (TextView)findViewById(R.id.result_screen_points);
        String highScoreStr = getResources().getString(R.string.lbl_results_highscore);
        pointsView.setText(Integer.toString(points) + (highScore ? highScoreStr : ""));

        RatingBar ratingBar = (RatingBar)findViewById(R.id.result_screen_rating);
        ratingBar.setRating(level.getStarCount(points));
        
        Button closeButton = (Button)findViewById(R.id.result_screen_close);
        closeButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View view)
            {
                ResultScreen.this.finish();
            }
        });
    }
}
