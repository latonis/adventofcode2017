if [[ -z "$YEAR" || -z "$SESSION_TOKEN" ]]; then 
echo "Please provide the year (YEAR) and session token (SESSION_TOKEN)"
exit -1
fi

url="https://adventofcode.com"
url_day="${url}/$YEAR/day"

mkdir static
curl "${url}/static/style.css" > static/style.css

for i in $(seq 25)
do
        mkdir day$i
        curl "${url_day}/${i}" > day${i}/index.html
        curl --cookie "session=$SESSION_TOKEN" "${url_day}/${i}/input" > day${i}/input
done