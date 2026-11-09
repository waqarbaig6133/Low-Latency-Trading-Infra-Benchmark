#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Node
{
	std::string hostname;
	std::string role;
	int cpu_count;
	std::string nic = "eth0";
	std::unordered_map<std::string, int> pillar;
};

int main()
{
	std::unordered_map<int, Node> FLEET;

	FLEET[0] = {
		.hostname = "md-feed-01",
		.role = "feed",
		.cpu_count = 8,
		.pillar = {{"tick_rate", 50000}, {"symbols", 200}}};

	FLEET[1] = {
		.hostname = "trade-01",
		.role = "trading",
		.cpu_count = 16,
		.pillar = {{"hot_cpu", 3}, {"irq_cpus", {0, 1}}, {"busy_poll_us", 50}}};

	FLEET[2] = {
		.hostname = "trade-02",
		.role = "trading",
		.cpu_count = 16,
		.pillar = {{"hot_cpu", 3}, {"irq_cpus", {0, 1}}, {"busy_poll_us", 50}}};

	return 0;
}

	Node(
        hostname="trade-02",
        role="trading",
        cpu_count=16,
        pillar={"hot_cpu": 5, "irq_cpus": [0, 1], "busy_poll_us": 50},
    ),
    Node(
        hostname="metrics-01",
        role="metrics",
        cpu_count=4,
        pillar={"retention_days": 7},
    ),
]


def nodes_with_role(role: str) -> list[Node]:
    """Query the desired fleet by role. Renderers iterate these."""
    return [n for n in FLEET if n.role == role]