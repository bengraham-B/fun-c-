#!/bin/bash

read message


git add .
git commit -m "$message"
git push

echo " "
echo Pushed to Github Successfully [200]
echo " "

git status
