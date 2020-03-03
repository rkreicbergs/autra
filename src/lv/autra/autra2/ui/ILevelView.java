
package lv.autra.autra2.ui;

public interface ILevelView
{
    public void toogleButtons(final boolean enabled);

    public void displayTime(final long time);

    public void displayPoints(final int totalPoints, final int points);

    public void displayPoints(final int totalPoints);

    public void onLevelDone(int points);
}
