#!/bin/zsh
icon="~/Pictures/clock.png"
time="$(date +%H:%M)"
text="Time: $(date +%T)               Date: $(date +%D), $(date +%A)"
notify-send -i $icon "$time" "$text"
