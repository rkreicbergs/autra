
package lv.autra.autra2.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.LinearLayout;
import lv.autra.autra2.R;
import lv.autra.autra2.game.Game;

public class GameSelect extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.game_select);

        LinearLayout layout = (LinearLayout)findViewById(R.id.game_select_layout);
        LayoutParams layoutParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);

        String[] gameNames = getResources().getStringArray(R.array.GameNames);
        for (final Game game : Game.getAllGames())
        {
            Button gameBtn = new Button(this);
            gameBtn.setText(gameNames[game.gameType]);
            gameBtn.setAllCaps(false);
            gameBtn.setOnClickListener(new View.OnClickListener()
            {
                public void onClick(View view)
                {
                    Intent i = new Intent(GameSelect.this, LevelSelect.class);
                    i.putExtra("gameType", game.gameType);
                    startActivity(i);
                }
            });
            layout.addView(gameBtn, layoutParams);
        }
    }
}
