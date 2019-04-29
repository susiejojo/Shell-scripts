#!/bin/zsh
#displays current time,day and date
#make sure u have a clock.png saved in ~/Pictures/
icon="~/Pictures/clock.png"
time="$(date +%H:%M)"
text="Time: $(date +%T)               Date: $(date +%D), $(date +%A)"
notify-send -i $icon "$time" "$text"
