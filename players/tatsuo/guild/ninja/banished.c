// Darastor 211197: Banished command from old version of guild soul

#define BANISHED    "/players/tatsuo/ezo/fconference"
#define TP          this_player()

int main(string str)
{
    if(str)
        return 0;
        
    tell_object(TP, BANISHED->banish_info(TP->query_real_name()));
    return 1;
}

