## 1. What are the pillars of Wi-Fi security? 
ans: 

**i. Authentication**  
- Verifies user/device identity before network access.  
- eg: WPA2/WPA3, 802.1X.

**ii. Encryption**
- Protects data from eavesdropping.  
- eg: Uses AES, WPA3, SAE.

**iii. Integrity**  
- Ensures data isn’t altered in transit.  
- eg: Uses MIC, GCMP.

**iv. Access Control**  
- Limits what devices/users can access.  
- eg: VLANs, NAC, firewalls.

**v. Monitoring**  
- Detects threats and rogue devices.  
- eg: WIDS/WIPS, logging.

## 2. Explain the difference between encryption and authentication in Wi-Fi security.
ans:

**Authentication**  
- **Purpose:** Verifies who is trying to connect to the network.  
- **What it does:** Ensures only authorized users/devices can join.  
- **Example:**  
  - WPA2-PSK: User enters a shared password.  
  - WPA2/WPA3-Enterprise: Uses username/password or certificates via a RADIUS server.

**Encryption**  
- **Purpose:** Protects data sent over the wireless network.  
- **What it does:** Scrambles data so outsiders can’t read it.  
- **Example:** AES encryption in WPA2/WPA3 keeps traffic private even if intercepted.

**Key Difference:**
- **Authentication** = Verifying identity  
- **Encryption** = Protecting data confidentiality

## 3. Explain the difference between WEP, WPA, WPA2 and WPA3.
ans:
| Feature        | **WEP**                   | **WPA**                         | **WPA2**                        | **WPA3**                          |
|----------------|---------------------------|----------------------------------|----------------------------------|------------------------------------|
| **Encryption** | RC4 (weak, outdated)      | TKIP (improved RC4)              | AES (strong encryption)          | AES with SAE, GCMP (more secure)   |
| **Authentication** | Pre-shared key (PSK) only | PSK or 802.1X                    | PSK or 802.1X                    | SAE (stronger than PSK), 802.1X    |
| **Security Level** | Very weak                | Moderate (now outdated)          | Strong (still widely used)       | Very strong (current best)         |
| **Vulnerabilities** | Easily cracked in seconds | TKIP vulnerable, deprecated      | Vulnerable to brute force if weak PSK | Resistant to offline attacks     |

## 4. Why is WEP considered insecure compared to WPA2 or WPA3?
ans: 

**Why WEP Is Insecure:**

a. **Weak Encryption**: Uses outdated RC4 cipher and small 24-bit IV, easily cracked.  
b. **Static Keys**: Same key reused; no dynamic key exchange.  
c. **No Key Management**: No secure method to update or rotate keys.  
d. **Vulnerable to Attacks**: Tools can break WEP in minutes via packet sniffing.  
e. **No Replay Protection**: Allows attackers to resend and analyze packets.

**WPA2/WPA3 Improvements:**

- Use AES encryption.  
- Support dynamic key exchange and secure handshakes.  
- WPA3 adds SAE for even stronger protection and forward secrecy.


## 5. Why was WPA2 introduced?
ans: 

- **Stronger Encryption:** Introduced AES (Advanced Encryption Standard) to replace insecure RC4 used in WEP and WPA.
- **Improved Security Protocol:** Implemented the CCMP protocol for data integrity & confidentiality, more secure than WPA’s TKIP.
- **Compliance with IEEE 802.11i:** Fully aligned with the official Wi-Fi security standard, unlike WPA which was a stopgap.
- **Support for Enterprise Networks:** Provided robust support for 802.1X authentication and RADIUS servers for large-scale deployments.

## 6. What is the role of PMK in the 4-way handshake? 
ans: 
The **Pairwise Master Key (PMK)** plays a central role in the **4-way handshake** process in WPA/WPA2/WPA3 Wi-Fi security, enabling secure communication between a client (supplicant) and an access point (authenticator).
**Role of PMK in the 4-Way Handshake**
### 1. **Key Foundation**:  
   The PMK is the **base key** derived from:
   - A pre-shared key (PSK) in WPA/WPA2-Personal, or  
   - 802.1X authentication (e.g., via RADIUS) in WPA/WPA2-Enterprise.

### 2. **Session Key Generation**:  
   The PMK is used to derive the Pairwise Transient Key (PTK), which is unique per session and per client.

### 3. **Secure Exchange**:  
   The 4-way handshake securely exchanges nonces (random numbers) and derives the PTK from:
   - PMK  
   - Nonces from client (SNonce) and AP (ANonce)  
   - MAC addresses of both parties

### 4. **Encryption Activation**:  
   Once both sides derive the same PTK from the PMK, they begin encrypting traffic using it, ensuring confidentiality and integrity.

## 7. How does the 4-way handshake ensure mutual authentication between the client and access point?
ans: 
- The access point sends a random number (ANonce) to the client.
- The client generates its own random number (SNonce) and uses it, along with the ANonce and PMK, to derive a session key (PTK). It sends the SNonce and a MIC (message integrity code) to the AP.
- The access point uses the same inputs to derive its PTK. If the client's MIC is valid, the AP confirms the client has the correct PMK.
- The AP then sends its own MIC to the client. If the client validates it, the AP is authenticated.
- Both parties now trust that the other knows the PMK, achieving mutual authentication without transmitting the PMK itself.


## 8. What will happen if we put a wrong passphrase during 4-way handshake? 
ans: 
a. Client Sends Incorrect PMK:
- The client derives a Pairwise Master Key (PMK) from the incorrect passphrase.

b. Mismatched PTK Generation:
- During the handshake, both the client and access point independently derive a Pairwise Transient Key (PTK) using the PMK and exchanged nonces.
With a wrong PMK, the client's PTK won't match the AP's.

c. MIC Verification Fails:
- The Message Integrity Code (MIC) sent by the client will not match what the AP expects. The AP detects this and aborts the handshake.

d. No Network Access:
- Since mutual authentication fails, the client cannot join the network or exchange encrypted data.

## 9. What problem does 802.1x solve in a network? 
ans: 

#### 1. **Unauthorized Access to the Network**

- Without authentication, any device that connects to a switch port or Wi-Fi can access the network.
- 802.1X requires authentication before allowing any access, reducing the risk of rogue users or devices joining the network.

#### 2. **Weak Shared Credentials**
- In traditional networks (e.g., WPA2-Personal), a single pre-shared key (PSK) is used for all devices.
- If the key is leaked, anyone can access the network.
- 802.1X replaces PSKs with individual credentials (username/password, certificates), making it more secure and manageable.

#### 3. **Lack of Centralized Control**
- Without centralized control, managing access for hundreds or thousands of users is complex.
- 802.1X integrates with RADIUS servers to centrally authenticate users and apply access policies (e.g., VLAN, access restrictions).

#### 4. **Guest and BYOD Device Management**
- 802.1X can redirect unauthenticated or unknown devices (e.g., guest laptops or mobile phones) to captive portals or assign them to restricted **VLANs**, rather than giving full access.
- This improves network segmentation and compliance.

#### 5. **Support for Dynamic Access Policies**
- Based on identity, device type, or role, 802.1X allows the network to apply dynamic VLANs, QoS settings, or firewall rules.
- For example, employees and IoT devices can be placed in different virtual LANs with appropriate access rights.


## 10. How does 802.1x enhance security over wireless networks? 
ans: 

**a. Individual User Authentication:** Each user or device must log in with unique credentials (e.g., username/password or certificate), preventing unauthorized access.

**b. No Shared Passwords:** Eliminates the need for a common Wi-Fi password, reducing the risk of password leaks or misuse.

**c. Per-Session Encryption Keys:** Generates unique encryption keys for each session after authentication, protecting data from eavesdropping.

**d. Centralized Access Control:** Works with a RADIUS server to enforce user-specific policies and allows administrators to revoke access without changing the network settings.

**e. Stronger Authentication Options:** Supports certificate-based authentication, which is more secure than passwords and resists phishing and brute-force attacks.
