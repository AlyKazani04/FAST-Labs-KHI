import socket as s

ports = [17, 21, 22, 25, 53, 69, 80, 107, 443, 6379]

print(f"PORT\tTCP Service\tUDP Service\n{'-' * 40}")

for port in ports:
    try:
        tcp_serv = s.getservbyport(port, "tcp")
    except Exception:
        tcp_serv = "Unknown"

    try:
        udp_serv = s.getservbyport(port, "udp")
    except Exception:
        udp_serv = "Unknown"

    print(f"{port}\t{tcp_serv}\t\t{udp_serv}")
