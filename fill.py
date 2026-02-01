import os
import random
from datetime import datetime, timedelta

start = datetime(2026, 2, 1)
end = datetime(2026, 3, 30)

current = start

while current <= end:
    commits_per_day = random.randint(6, 12)

    for i in range(commits_per_day):
        time_offset = random.randint(0, 86400)
        commit_time = current + timedelta(seconds=time_offset)
        date_str = commit_time.strftime("%Y-%m-%dT%H:%M:%S")

        with open("log.txt", "a") as f:
            f.write(date_str + "\n")

        os.system("git add .")

        # Windows-compatible way
        os.environ["GIT_AUTHOR_DATE"] = date_str
        os.environ["GIT_COMMITTER_DATE"] = date_str

        os.system(f'git commit -m "fill {date_str}"')

    current += timedelta(days=1)

os.system("git push")