#define HELPDIR         "/players/tatsuo/guild/helpdir/"
#define GM              "/guild/master"
#define TP              this_player()
#define GUILD_NUMBER    8

// Need accurate helpdir define
// Need help written for nshake

int main(string str)
{
    string path;

    if(!str)
        return 0;

    if(str == "levels")
    {
        GM->list_levels(GUILD_NUMBER,TP->query_gender());
        return 1;
    }
    else if(str == "legendlevels")
    {
        GM->list_legend_levels(GUILD_NUMBER,TP->query_gender());
        return 1;
    }
    
    path = HELPDIR + (explode(str," ")[0]);
    if(file_size(path) >= 0)
        cat(path);
    else
        return 0;
    return 1;
}
