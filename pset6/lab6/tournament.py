import csv
import sys
import random
import time

# Number of simulations to run
N = 10000


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # Read teams into memory from file
    filename = sys.argv[1]
    start_load = time.time()
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            row["rating"] = int(row["rating"])
            teams.append(row)
    end_load = time.time()
    load_time = end_load - start_load

    counts = {}
    # Simulate N tournaments and keep track of win counts
    start_sim = time.time()
    for simulacao in range(N):
        winningTeam = simulate_tournament(teams)
        if winningTeam in counts:
            counts[winningTeam] += 1
        else:
            counts[winningTeam] = 1
    end_sim = time.time()
    sim_time = end_sim - start_sim

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    # Write execution times to answers.txt
    with open("answers.txt", "w") as f:
        f.write(f"Load Time: {format_time(load_time)}\n")
        f.write(f"Simulation Time: {format_time(sim_time)}\n")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    while len(teams) > 1:
        winners = []
        for i in range(0, len(teams), 2):
            if simulate_game(teams[i], teams[i + 1]):
                winners.append(teams[i])
            else:
                winners.append(teams[i + 1])
        teams = winners
    return teams[0]['team']


def format_time(seconds):
    """Format time in hours, minutes, and seconds."""
    m, s = divmod(seconds, 60)
    h, m = divmod(m, 60)
    return f"{int(h)}h{int(m)}m{int(s)}s"


if __name__ == "__main__":
    main()
