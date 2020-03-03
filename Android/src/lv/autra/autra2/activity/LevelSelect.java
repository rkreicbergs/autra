
package lv.autra.autra2.activity;

import android.content.Intent;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentStatePagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout.LayoutParams;
import android.widget.TableLayout;
import android.widget.TableRow;
import lv.autra.autra2.R;
import lv.autra.autra2.game.Game;
import lv.autra.autra2.game.Level;

public class LevelSelect extends FragmentActivity
{
    GameAdapter mAdapter;
    ViewPager mViewPager;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.level_select);

        Bundle b = getIntent().getExtras();
        final Game game = Game.get(b.getInt("gameType"));
        String gameName = getResources().getStringArray(R.array.GameNames)[game.gameType];
        setTitle(gameName);

        mAdapter = new GameAdapter(getSupportFragmentManager(), game);
        mViewPager = (ViewPager)findViewById(R.id.game_pager);
        mViewPager.setAdapter(mAdapter);
    }

    public static class GameAdapter extends FragmentStatePagerAdapter
    {
        final Game game;

        public GameAdapter(FragmentManager fm, Game game)
        {
            super(fm);
            this.game = game;
        }

        @Override
        public int getCount()
        {
            return game.tabNames.length;
        }

        @Override
        public CharSequence getPageTitle(int tabIdx)
        {
            return game.tabNames[tabIdx];
        }

        @Override
        public Fragment getItem(int tabIdx)
        {
            Bundle b = new Bundle();
            b.putInt("gameType", game.gameType);
            b.putInt("tabIdx", tabIdx);

            GameAdapterFragment frag = new GameAdapterFragment();
            frag.setArguments(b);
            return frag;
        }
    }

    public static class GameAdapterFragment extends Fragment
    {
        Game game;
        int tabIdx;

        @Override
        public void onCreate(Bundle savedInstanceState)
        {
            super.onCreate(savedInstanceState);
            game = Game.get(getArguments().getInt("gameType"));
            tabIdx = getArguments().getInt("tabIdx");
        }

        static private int getLevelBtnColor(int starCount)
        {
            switch (starCount)
            {
            case 3:
                return Color.RED;
            case 2:
                return Color.BLUE;
            case 1:
                return Color.GREEN;
            default:
                return 0xFFAE7552;
            }
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState)
        {
            View v = inflater.inflate(R.layout.level_select_page, container, false);
            TableLayout tLayout = (TableLayout)v.findViewById(R.id.game_btn_table);
            LayoutParams rowParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
            TableRow.LayoutParams buttonParam = new TableRow.LayoutParams();

            int rowLength = 5;
            if (game.levels[game.tabStartLevelId[tabIdx] + 6].isExam)
            {
                rowLength = 7;
            }
            
            TableRow tableRow = null;
            for (int i = 0; i < game.tabSizes[tabIdx]; ++i)
            {
                final Level level = game.levels[game.tabStartLevelId[tabIdx] + i];
                int color = getLevelBtnColor(level.starCount);

                if (i % rowLength == 0)
                {
                    tableRow = new TableRow(getActivity());
                    tLayout.addView(tableRow, rowParams);
                }

                Button levelBtn = new Button(getActivity());
                levelBtn.setText(Integer.toString(level.levelId + 1));
                levelBtn.setTextSize(14);
                levelBtn.getBackground().setColorFilter(color, PorterDuff.Mode.MULTIPLY);
                levelBtn.setOnClickListener(new View.OnClickListener()
                {
                    public void onClick(View view)
                    {
                        Intent i = new Intent(getActivity(), level.isTriggerLevel() ? TriggerLevel.class : ChoiceLevel.class);
                        i.putExtra("gameType", level.gameType);
                        i.putExtra("levelId", level.levelId);
                        startActivity(i);
                    }
                });
                tableRow.addView(levelBtn, buttonParam);
            }

            return v;
        }
    }
}
