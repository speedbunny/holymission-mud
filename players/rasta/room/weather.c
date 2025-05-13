/* From: geoff@bruce.cs.monash.OZ.AU (Geoff Wong) */
 
/*
	Nevyn (rendell@bruce.cs.monash.edu.au)
*/
#define HOURS 24
#define MINUTES 60
 
object next_weather_object;
 
query_next() { return next_weather_object; }
link(obj) { next_weather_object = obj; }
 
/*    outdoorness    {none, indoors, indoors(windows), under cover, exposed}
 
    cloud cover    {clear, light, heavy, overcast}
    precipitation    {none, spitting, light, storm, thunder storm}
    humidity    {none, fog, mist}
    wind        {still, light, breezy, windy, strong wind, gale force}
    temperature    {cold, chilly, temperate, warm, hot}
    sun/moon    {one or the other, plus phase for the moon? }
*/
 
int sky_cloud;
int sky_precipitation;
int sky_humidity;
int sky_wind;
int sky_temperature;
int sky_night;
 
object calendar;
 
reset(arg) {
    if (arg)
        return;
    "obj/game_clock"->query_date();
    calendar = find_object("obj/game_clock");
    calendar->add_weather_object(this_object());
    reset_weather();
}
 
init() {}
 
sky_query_long(arg, outdoors)
{
	string mess;
 
    if (outdoors < 2)
        return 0;
    if ((arg == "sky") || (arg == "at sky") ||
        ((outdoors == 2) && ((arg == "outdoors") || (arg == "outside"))))
	{
		if (mess = desc_weather(outdoors))
			tell_object(this_player(), capitalize(mess)+"\n");
	}
    else if ((arg == "sun") || (arg == "at sun"))
        if (sky_night == 0)
            tell_object(this_player(), "You now have sore eyes.\n");
        else
            tell_object(this_player(), "The sun has set!\n");
    else if ((arg == "moon") || (arg == "at moon"))
        tell_object(this_player(), moon()+"\n");
    else
        return 0;
    return 1;
}
 
sky_query_weather(outdoors)
{
     int i;
     string mess,mess2,tmp;
     if (outdoors) /*  && (sky_precipitation || sky_humidity || sky_night) */
	  if (mess = desc_weather(outdoors))
	       tell_object(this_player(), capitalize(mess)+"\n");
}
 
query_cloud() { return sky_cloud; }
 
query_precipitation() { return sky_precipitation; }
 
query_humidity() { return sky_humidity; }
 
query_wind() { return sky_wind; }
 
query_temperature() { return sky_temperature; }
 
query_night() { return sky_night; }
 
change_weather(new_cloud, new_precipitation, new_humidity, new_wind,
new_temperature, new_night)
{
    single_change_weather(({new_cloud, new_precipitation, new_humidity,
new_wind, new_temperature, new_night}));
}
 
single_change_weather(array)
{
    int i;
    object user_array;
    string thing;
    int new_cloud, new_precipitation, new_humidity, new_wind;
    int new_temperature, new_night;
 
    new_cloud = array[0];
    new_precipitation = array[1];
    new_humidity = array[2];
    new_wind = array[3];
    new_temperature = array[4];
    new_night = array[5];
    user_array = users();
    i = 0;
    while (i < sizeof(user_array))
    {
        if (environment(user_array[i]))
            if (environment(user_array[i])->query_weather_obj() == this_object())
            {
                thing=environment(user_array[i])->sky_change_weather(new_cloud,
new_precipitation, new_humidity, new_wind, new_temperature, new_night);
                if (thing)
                    tell_object(user_array[i], thing);
            }
        i += 1;
    }
    i = 0;
    if (new_cloud >= 100)
        i = 1;
    else if (new_cloud >= 0) sky_cloud = new_cloud;
    if (new_precipitation >= 100)
        i = 1;
    else if (new_precipitation >= 0) sky_precipitation = new_precipitation;
    if (new_humidity >= 100)
        i = 1;
    else if (new_humidity >= 0) sky_humidity = new_humidity;
    if (new_wind >= 100)
        i = 1;
    else if (new_wind >= 0) sky_wind = new_wind;
    if (new_temperature >= 100)
        i = 1;
    else if (new_temperature >= 0) sky_temperature = new_temperature;
    if (new_night >= 100)
        i = 1;
    else if (new_night >= 0) sky_night = new_night;
    if (i > 0)
        call_out("single_change_weather", 60, ({new_cloud - 100,
new_precipitation - 100, new_humidity - 100, new_wind - 100,
new_temperature - 100, new_night - 100}));
    return 1;
}
 
desc_weather(outdoors)
{
    string sky;
    int visible;
 
    if (outdoors == 0)
        return 0;
	if (outdoors == 1)
		if (sky_precipitation)
			return roof_precip();
		else
			return 0;
    visible = 1;
    if (sky_humidity)
        if (sky_precipitation)
            sky = humidity() + "  " + capitalize(precip()) + "bove.";
        else
            sky = humidity();
    else
        sky = precip();
    if (extract(sky, strlen(sky)-1, strlen(sky)-1) != ".")
        sky = sky + " " + temp() + wind1() + ", " + cloud() + ".";
    else
        visible = 0;
    if (outdoors == 2 && sky_precipitation)
		return roof_precip() + "  Outside, "+ sky;
    if (outdoors == 2)
        sky = "outside, "+sky;
    if (outdoors > 2)
    {
        if (sky_wind)
            sky = sky + "  " + wind2();
        if (visible && sky_night)
            sky = sky + "  " + moon();
    }
    return sky;
}
 
cloud()
{
    string night;
 
    if (sky_night)
        night = " night ";
    else
        night = " ";
    if (sky_cloud == 0)
        return "clear"+night+"sky";
    else if (sky_cloud == 1)
        return "lightly clouded"+night+"sky";
    else if (sky_cloud == 2)
        return "cloudy"+night+"sky";
    else if (sky_cloud == 3)
        return "heavily clouded"+night+"sky";
}
 
temp()
{
    if (sky_precipitation < 2)
    {
        if (sky_temperature == 0)
            return "cold, ";
        else if (sky_temperature == 1)
            return "chilly, ";
        else if (sky_temperature == 2)
            return "";
        else if (sky_temperature == 3)
            return "warm, ";
        else if (sky_temperature == 4)
            return "hot, ";
    }
    else
        return "";
}
 
roof_precip()
{
    if ((sky_precipitation == 1) && (sky_temperature == 1))
        return "occasional thuds sound from above your head.";
    else if ((sky_precipitation == 2) && (sky_temperature == 1))
        return "thuds sound from above.";
    else if ((sky_precipitation == 2) && (sky_temperature > 1))
        return "you hear pattering above your head.";
    else if ((sky_precipitation > 2) && (sky_temperature > 0))
        return "a continuous drumming noise sounds from above your head.";
    else return "";
}
 
precip()
{
    if (sky_precipitation == 0)
    {
        if (sky_temperature == 0)
            return "above you is a";
        else if (sky_temperature == 1)
            return "above you is a";
        else if (sky_temperature == 2)
            return "above you is a";
        else if (sky_temperature == 3)
            return "above you is a";
        else if (sky_temperature == 4)
            return "above you is a";
    }
    else if (sky_precipitation == 1)
    {
        if (sky_temperature == 0)
            return "occasional snow flakes fall from a";
        else if (sky_temperature == 1)
            return "occasional hail stones fall from a";
        else if (sky_temperature == 2)
            return "it is lightly spitting from a";
        else if (sky_temperature == 3)
            return "it is lightly spitting from a";
        else if (sky_temperature == 4)
            return "it is lightly spitting from a";
    }
    else if (sky_precipitation == 2)
    {
        if (sky_temperature == 0)
            return "snow falls from a";
        else if (sky_temperature == 1)
            return "hail stones fall from a";
        else if (sky_temperature == 2)
            return "rain falls from a";
        else if (sky_temperature == 3)
            return "warm rain falls from a";
        else if (sky_temperature == 4)
            return "hot rain falls from a";
    }
    else if (sky_precipitation == 3)
    {
        if (sky_temperature == 0)
            return "snow fills the air.";
        else if (sky_temperature == 1)
            return "rain and hail drums down from a";
        else if (sky_temperature == 2)
            return "rain drums the ground from a";
        else if (sky_temperature == 3)
            return "warm rain drums the ground from a";
        else if (sky_temperature == 4)
            return "hot rain drums the ground from a";
    }
    else if (sky_precipitation == 4)
    {
        if (sky_temperature == 0)
            return "a freezing blizzard obscures your sight from a";
        else if (sky_temperature == 1)
            return "sleet pours down from a";
        else if (sky_temperature == 2)
            return "torrential rain pours down from a";
        else if (sky_temperature == 3)
            return "hot torrential rain pours down from a";
        else if (sky_temperature == 4)
            return "steaming torrential rain pours down from a";
    }
    return "";
}
 
humidity()
{
    if (sky_humidity == 1)
        return "a light mist dims your sight.";
    else if (sky_humidity == 2)
        return "a heavy fog obscures your sight.";
    return "";
}
 
wind1()
{
    if (sky_wind == 0)
        return "still";
    else if ((sky_wind == 1) || (sky_wind == 2))
        return "slowly moving";
    else if (sky_wind == 3)
        return "moving";
    else if (sky_wind == 4)
        return "roiling";
    else if (sky_wind == 5)
        return "racing";
    return "";
}
 
wind2()
{
    if (sky_wind == 0)
        return "";
    else if (sky_wind == 1)
        return "A light wind stirs the air.";
    else if (sky_wind == 2)
        return "A breeze blows around you.";
    else if (sky_wind == 3)
        return "There is a brisk wind.";
    else if (sky_wind == 4)
        return "You have to brace yourself against the strong wind.";
    else if (sky_wind == 5)
        return "A gale force wind blasts you.";
    return "";
}
 
moon()
{
    if (!calendar)
        return "";
    if (!sky_humidity && (sky_cloud < 2) && (sky_night > 0) &&
(calendar->query_moon() != "new"))
        return "A "+calendar->query_moon()+" moon hangs in the sky.";
    else
        return "The moon is not visible.";
}
 
reset_weather()
{
    todays_weather(calendar->convert_hours_minutes(calendar->query_hour(), calendar->query_minute()));
}
 
midnight()
{
    todays_weather(0);
}
 
todays_weather(t)
{
    int dawn, dusk, latest;
    int temp, cool_change, warm_change, change, curr;
    int humid, precip;
    int event_time, other;
    string season;
 
    season = calendar->query_season();
    if (season == "summer")
    {
        dawn = calendar->convert_hours_minutes(5, 0) - t;
        dusk = calendar->convert_hours_minutes(21, 0) - t;
        temp = 3;
        cool_change = 2;
        warm_change = 5;
        humid = 0;
        precip = -1;
    }
    else if (season == "winter")
    {
        dawn = calendar->convert_hours_minutes(7, 0) - t;
        dusk = calendar->convert_hours_minutes(19, 0) - t;
        temp = 1;
        cool_change = 5;
        warm_change = 2;
        humid = 2;
        precip = 1;
    }
    else
    {
        dawn = calendar->convert_hours_minutes(6, 0) - t;
        dusk = calendar->convert_hours_minutes(20, 0) - t;
        temp = 2;
        if (season == "autumn")
        {
            cool_change = 5;
            warm_change = 5;
        }
        else
        {
            cool_change = 2;
            warm_change = 2;
        }
        humid = 1;
        precip = 0;
    }
    if (dawn > 0)
        call_out("single_change_weather", dawn, ({-1,-1,-1,-1,-1,300}));
    if (dusk > 0)
        call_out("single_change_weather", dusk, ({-1,-1,-1,-1,-1,301}));
    event_time = calendar->convert_hours_minutes(random(HOURS), random(MINUTES)) - t;
    if (event_time > 0)
    {
        curr = random(15);
        if (curr < 3)
            curr = 0;
        else if (curr < 6)
            curr = 1;
        else if (curr < 10)
            curr = 2;
        else if (curr < 13)
            curr = 3;
        else if (curr < 15)
            curr = 4;
        else
            curr = 5;
        if (curr != sky_wind)
            call_out("single_change_weather", event_time, ({-1,-1,-1,curr+100,-1,-1}));
        if (dawn > 0)
        {
            latest = 0;
            if (event_time > dawn)
            {
                if (!sky_wind && curr)
                    latest = event_time;
                else if (sky_wind)
                    latest = -1;
            }
            else if (!curr)
                latest = -1;
        }
 
    }
    if (t && (dawn > 0 || dusk < 0))
        change_weather(-1, -1, -1, -1, -1, 1);
    if (t || sky_temperature > temp+1 || sky_temperature < temp-1)
        change_weather(-1, -1, -1, -1, temp, -1);
    else
    {
        change = 0;
        if (sky_temperature == temp)
        {
            curr = 0;
            if (random(10) < cool_change)
                change = -1;
        }
        else
        {
            curr = -1;
            if (random(10) < warm_change)
                change = 1;
        }
        if (change)
            event_time = calendar->convert_hours_minutes(random(HOURS), random(MINUTES));
        else
            event_time = -1;
        other = dawn + calendar->convert_hours_minutes(random(4-temp), random(MINUTES));
        if (other > event_time)
        {
            if (event_time > 0)
                temp_change(event_time, temp+curr+change); /*change occurs at night*/
            temp_change(other, temp+1+curr+change);
            if (temp+curr+change < 2 && latest != -1)
            {
                call_out("single_change_weather", dawn, ({-1,-1,humid,-1,-1,-1}));
                other = dawn + calendar->convert_hours_minutes(random(2), random(MINUTES));
                if (latest && other > latest)
                    other = latest;
                call_out("single_change_weather", other, ({-1,-1,100,-1,-1,-1}));
            }
            other = dusk + calendar->convert_hours_minutes(random(temp), random(MINUTES));
            temp_change(other, temp+curr+change);
        }
        else
        {
            temp_change(other, temp+1+curr); /* change occurs after dawn... */
            if (event_time < latest && temp+1+curr+change > 1)
                latest = event_time;
            if (temp+curr < 2 && latest != -1)
            {
                call_out("single_change_weather", dawn, ({-1,-1,humid,-1,-1,-1}));
                other = dawn + calendar->convert_hours_minutes(random(2), random(MINUTES));
                if (latest && other > latest)
                    other = latest;
                call_out("single_change_weather", other, ({-1,-1,100,-1,-1,-1}));
            }
 
            other = dusk + calendar->convert_hours_minutes(random(temp), random(MINUTES));
            if (other > event_time)
            {
                temp_change(event_time, temp+1+curr+change); /* ...but before dusk */
                temp_change(other, temp+curr+change);
            }
            else
            {
                temp_change(other, temp+curr);
                temp_change(event_time, temp+curr+change); /* ...and after dusk */
            }
        }
    }
    if (change == -1 && random(2)) /* 50% chance of rain after a cool change */
    {
        curr = 2+random(2);
        if (curr < sky_cloud)
            curr = sky_cloud;
        call_out("single_change_weather", event_time + random(10), ({100+curr,-1,-1,-1,-1,-1}));
        precip += 2 + random(3);
        if (precip > 4)
            precip = 4;
        if (precip < sky_precipitation)
            precip = sky_precipitation;
        if (precip > curr+1)
            precip = curr+1;
        call_out("single_change_weather", event_time + 10 + random(10), ({-1,100+precip,-1,-1,-1,-1}));
        call_out("single_change_weather", event_time + calendar->convert_hours_minutes(random(2)+1, random(MINUTES)), ({-1,100+sky_precipitation,-1,-1,-1,-1}));
    }
    else
    {
        event_time = calendar->convert_hours_minutes(random(HOURS), random(MINUTES)) - t;
        if (event_time > 0)
        {
            curr = random(4);
            call_out("single_change_weather", event_time, ({curr,-1,-1,-1,-1,-1}));
            precip += random(5);
            if (precip > 4) precip = 4;
            if (precip < 0) precip = 0;
            if (precip > curr+1) precip = curr+1;
            call_out("single_change_weather", event_time + 10 + random(10), ({-1,100+precip,-1,-1,-1,-1}));
            call_out("single_change_weather", event_time + calendar->convert_hours_minutes(random(2)+1, random(MINUTES)), ({-1,100+sky_precipitation,-1,-1,-1,-1}));
        }
    }
}
 
temp_change(t, temp)
{
    call_out("single_change_weather", t, ({-1,-1,-1,-1,100+temp,-1}));
}
 
query_call_outs()
{
    int i;
 
    if ((i = find_call_out("single_change_weather")) > 0)
        write("change: "+i+"\n");
}
 

