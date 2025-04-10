## 1. Brief about SplitMAC architecture and how it improves the AP's performance

Ans : **SplitMAC architecture** is a wireless network design that divides MAC layer functions between the Access Point (AP) and the Wireless LAN Controller (WLC).
Time-sensitive, real-time functions—such as beaconing, acknowledgments, and frame retransmissions—are handled locally by the AP to ensure low latency.
Meanwhile, higher-level control and management tasks—like client authentication, association, mobility management, and security policy enforcement—are centralized at the WLC.
This separation is enabled through CAPWAP tunneling between the AP and WLC. By offloading complex functions to the controller, the AP becomes simpler and more efficient, allowing easier deployment, centralized management, and improved performance in large-scale wireless networks.

Here are the benefits of SplitMAC architecture in point form:

-  Lightweight APs: APs are simpler and cost-effective since they handle only real-time functions.  
-  Centralized Management: WLC manages all APs from a single point, simplifying configuration and monitoring.  
-  Improved Roaming: Seamless handoff between APs due to centralized mobility management.  
-  Uniform Policy Enforcement: Security, QoS, and access policies are consistently applied across the network.  
-  Scalability: Easy to expand the network by adding more APs without complex setup.  
-  Efficient Resource Utilization: WLC optimizes channel assignment and power levels automatically.  
-  Reduced AP Processing Load: Offloading non-critical functions to the WLC frees up AP resources.  
-  Better Network Visibility: Central control allows detailed monitoring, diagnostics, and analytics.

## 2. Describe about CAPWAP, explain the flow between AP and Controller

Ans : CAPWAP (Control And Provisioning of Wireless Access Points) is a standardized protocol (defined in RFC 5415) used to manage the communication between Lightweight Access Points (APs) and a Wireless LAN Controller (WLC) in a SplitMAC architecture.
It allows centralized control of APs by tunneling both control and data messages over a secure IP connection. CAPWAP separates traffic into two tunnels:
- Control Tunnel: Used for management traffic (AP configuration, status, firmware updates).
- Data Tunnel: Used to carry client data traffic between APs and WLC.

CAPWAP Communication Flow Between AP and Controller
1. AP Boot-Up & Discovery : The AP powers on and broadcasts a CAPWAP Discovery Request. It discovers the WLC using methods like DHCP Option 43, DNS, or broadcast.
2. Join Process : The AP sends a Join Request to the discovered WLC. The WLC verifies and responds with a Join Response.
3. CAPWAP Tunnel Establishment : After joining, a Control Tunnel (for management/configuration) and optionally a Data Tunnel (for user data) are established over UDP ports (5246 for control, 5247 for data).
4. Configuration & Provisioning : The WLC sends configuration details (SSID, security policies, VLAN info) to the AP via the control tunnel.
5. Client Association : Clients associate with the AP, which forwards authentication and association requests to the WLC over the control tunnel.
6. Data Forwarding : Client data frames are tunneled to the WLC via the data tunnel, or optionally bridged locally by the AP in FlexConnect mode.
7. Monitoring and Updates : The AP periodically sends status updates, statistics, and keep-alive messages to the WLC.

## 3. Where this CAPWAP fits in OSI model, what are the two tunnels in CAPWAP and its purpose ?

Ans : CAPWAP primarily operates at Layer 3 (Network Layer) of the OSI model and above. It is built on top of UDP/IP:
- CAPWAP messages are encapsulated in UDP datagrams, enabling them to be routed across Layer 3 networks.
- Unlike older Layer 2 protocols (e.g., proprietary LWAPP), CAPWAP is not limited to a single broadcast domain and can manage APs across different IP subnets or over WAN links.
- This Layer 3 operation provides scalability and flexibility, especially in large enterprise networks where APs and WLCs may reside in different locations.

While the control and data tunnels are created over UDP (Layer 4), the actual management and data encapsulated in those tunnels pertain to Layer 7 (Application Layer) functions—such as configuration, policy enforcement, and monitoring.

## 4. What's the difference between Lightweight APs and Cloud-based APs ?

Ans : 

| **Aspect**                 | **Lightweight APs**                                      | **Cloud-Based APs**                                           |
|---------------------------|-----------------------------------------------------------|---------------------------------------------------------------|
| **Controller Requirement** | Requires a **physical WLC**                              | Managed via **cloud controller**                              |
| **Management Protocol**    | Uses **CAPWAP**                                          | Uses **HTTPS/REST APIs**                                      |
| **Control Plane**          | **Centralized**, handled by WLC                          | **Cloud-based**, controller functions hosted on the internet  |
| **Deployment**             | Suitable for **on-premise enterprise** setups            | Ideal for **distributed or remote** locations                 |
| **Scalability**            | Requires additional WLCs for scaling                     | **Easily scalable** via cloud portal                          |
| **AP Configuration**       | Configurations pushed by WLC                             | Configurations managed via cloud dashboard                    |
| **Maintenance & Updates**  | Done locally by IT staff                                 | **Automated** through cloud platform                          |
| **Internet Dependency**    | Functions on local network without internet              | **Requires internet** for full functionality and management   |
| **Cost Model**             | **Upfront hardware** investment                          | **Subscription-based** or **pay-as-you-go**                   |
| **Use Case**               | Best for large campuses, enterprises                     | Best for branches, SMBs, and remote offices                   |


## 5. How the CAPWAP tunnel is maintained between the AP and Controller, give as explanation ?

Ans : The CAPWAP tunnel between an Access Point (AP) and Wireless LAN Controller (WLC) is maintained through a series of steps and mechanisms that ensure a persistent, secure, and manageable communication channel.

**a. Discovery and Join Process**
- The AP starts by discovering the controller using **DHCP Option 43**, DNS resolution, or broadcast methods.
- Once discovered, the AP sends a **CAPWAP Discovery Request**.
- The WLC replies with a **CAPWAP Discovery Response**.
- The AP then sends a **Join Request**, and if accepted, the WLC replies with a **Join Response**, completing the join process.

**b. Tunnel Establishment**
- After joining, two **UDP-based tunnels** are established:
  - **Control Tunnel (UDP 5246)**: For management traffic (e.g., configuration, monitoring).
  - **Data Tunnel (UDP 5247)**: For forwarding client data packets.

**c. Security and Authentication**
- The control tunnel is often secured using **DTLS (Datagram Transport Layer Security)**.
- The AP and WLC authenticate each other and exchange encryption keys to protect the control messages.

**d. Keep-Alive and Heartbeats**
- The AP periodically sends **Echo Requests** to the WLC.
- The WLC replies with **Echo Responses**.
- If the controller doesn't respond within a timeout period, the AP marks the controller as unreachable and may restart the discovery process.

**e. Dynamic Updates and Maintenance**
- Configuration changes (like SSID, channel, RF power) are pushed through the control tunnel.
- The WLC continuously monitors AP status and client associations via the tunnel.
- Firmware upgrades can also be pushed through this tunnel.

## 6. What's the difference between Sniffer and monitor mode, use case for each mode ?

Ans : 

| **Aspect**             | **Sniffer Mode**                                           | **Monitor Mode**                                               |
|------------------------|-------------------------------------------------------------|----------------------------------------------------------------|
| **Purpose**            | Captures and analyzes **802.11 frames** for traffic monitoring | Listens to **all wireless traffic** on a channel without association |
| **Association**        | Typically **associated** with a specific AP or network      | **Not associated** with any AP or SSID                         |
| **Traffic Captured**   | Captures **data frames** between AP and clients             | Captures **all frames** (management, control, and data)        |
| **Header Information** | May not capture full 802.11 MAC headers                    | Captures **full 802.11 headers**, including radiotap info      |
| **Use Case**           | Useful for **troubleshooting specific network issues**      | Ideal for **wireless security auditing, passive scanning**     |

## 7. If WLC deployed in WAN, which AP Mode is best for local network and how ?

Ans : When a Wireless LAN Controller (WLC) is deployed over a Wide Area Network (WAN), the most suitable AP mode for ensuring reliable local network operation is **FlexConnect mode**.
This mode allows Access Points (APs) to maintain control communication with the remote WLC while intelligently handling user data traffic locally. 

In normal operation, the AP contacts the WLC for tasks like user authentication, policy enforcement, and configuration updates. However, instead of forwarding all client data traffic across the WAN to the WLC, the AP locally switches the data to the LAN, significantly reducing WAN bandwidth usage and improving efficiency.

The key advantage of FlexConnect is its resilience during WAN outages. If the connection to the WLC is lost, the AP can continue to operate in a standalone mode using cached configurations and credentials.
Clients connected to the AP can still access local resources like printers, local servers, and even internet access, depending on setup. Once connectivity to the WLC is restored, the AP automatically resynchronizes and resumes centralized operations. This makes FlexConnect ideal for branch offices or remote sites where uninterrupted local access is critical.

## 8. What are the challenges if deploying autonomous APs (more than 50) in large networks, like a university? 

Ans : Challenges of Deploying More Than 50 Autonomous APs in a Large Network (e.g., University):

a. Complex Management:
Each AP requires separate configuration and updates. Managing SSIDs, passwords, or firmware becomes tedious and time-consuming when done manually across dozens of devices.

b. Lack of Centralized Control:
There is no unified dashboard to monitor AP status, performance, or client issues. Troubleshooting requires logging into each AP individually, which is inefficient.

c. Poor Roaming Experience:
Since APs don't coordinate, devices moving across campus may face delays, packet loss, or dropped connections during handoff between APs.

d. Inefficient RF Management:
Autonomous APs cannot auto-adjust channel or power settings based on their neighbors, often causing interference and degraded wireless performance.

e. Scalability Issues:
Adding more APs increases administrative overhead linearly. There’s no smart user load balancing or dynamic configuration.

f. Security Inconsistencies:
Security settings must be applied manually to each AP, leading to potential configuration mismatches and vulnerabilities across the network.

g. Limited Client Visibility:
Network administrators can't easily view or manage client activity, session data, or bandwidth usage from a central location.

## 9. What happens on wireless clients connected to Lightweight IP in local mode if WLC goes down ?

Ans : When a Wireless LAN Controller (WLC) goes down, and Lightweight Access Points (LAPs) are operating in Local Mode, the impact on wireless clients is significant because these APs rely heavily on the controller for both control and data forwarding.

What Happens:
- Client Sessions Are Disrupted:  In Local Mode, the AP forwards all data traffic to the WLC, including client data. If the WLC becomes unreachable, the AP can no longer handle client data, causing all connected clients to get disconnected.

- No New Client Joins: Since the AP cannot process new authentication or association requests without the controller, new clients will not be able to connect to the network.

- No Local Switching: Local Mode APs do not have the capability to switch traffic locally. All operations—authentication, DHCP relay, VLAN tagging—require WLC intervention.

- APs Remain Powered but Idle: The APs stay powered on but enter a disconnected state, continuously trying to reconnect to the WLC.

Since both control and data are tunneled to the WLC, its absence causes total service loss.
