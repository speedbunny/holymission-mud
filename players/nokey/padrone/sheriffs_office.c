int wanted(object bandit, string crime, int reward)
{
    write("(Warning: Called wanted in old room. This should be changed.)\n");
    return (int)"players/padrone/inside/sheriffs_office"->wanted(bandit,crime,reward);
}
