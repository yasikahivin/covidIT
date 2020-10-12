# #!/usr/bin/env bash
# from="1 Oct, 2020"
# to="1 Nov, 2020"
# users=$(git shortlog -sn --no-merges --since="$from" --before="$to" | awk '{printf "%s %s\n", $2, $3}')
# IFS=$'\n'
# echo -e "User name;Files changed;Lines added;Lines deleted;Total lines (delta);Add./Del. ratio (1:n);Commit count"

# for userName in $users
# do
#     echo userName
#      result=$(git log --author="$userName" --no-merges --shortstat  --since="$from" --before="$to" \
# | grep -E "fil(e|es) changed" | awk '{files+=$1; inserted+=$4; deleted+=$6; delta+=$4-$6; ratio=deleted/inserted} \
# END {printf "%s;%s;%s;%s;%s", files, inserted, deleted, delta, ratio }' -)
# echo $result
#      countCommits=$(git shortlog -sn --no-merges  --since="$from" --before="$to" --author="$userName" \
# | awk '{print $1}')
#      if [[ ${result} != ';;;;' ]]
#      then
#         echo -e "$userName;$result;$countCommits"
#      fi
# done

export author="yasikahivin"
git ls-files | while read f; do replaceEscaped=$(sed 's/[&/\]/\\&/g' <<<"$f"); git blame -w --line-porcelain -- "$f" | grep -I '^author ' \
| sed s/^/"$replaceEscaped"" "/; done | grep "$author" | awk '{print $1}' | sort -f | uniq -ic | sort -n