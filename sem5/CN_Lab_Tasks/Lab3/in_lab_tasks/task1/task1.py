import socket as s

hostname = s.gethostname()
print(f"Hostname: {hostname}")

host = s.gethostbyname(hostname)

print(f"ip: {host}")
