## 1.What is the significance of MAC layer and in which position it is placed in OSI layer ?
ans:  
### MAC Layer – Technical Explanation
- The MAC layer is the lower sub-layer of the Data Link Layer (Layer 2) in the OSI model.
- The Data Link Layer is split into two sub-layers:
        1. LLC (Logical Link Control) – provides interface to the network layer and handles error checking and frame synchronization.
        2. MAC (Media Access Control) – handles actual transmission of data over the physical medium.

### Functions of the MAC Layer:

a. Medium Access Control:
- The MAC layer determines which device on a shared communication channel can transmit data and when.
- It implements media access protocols such as:
  - CSMA/CD (Carrier Sense Multiple Access with Collision Detection) – used in traditional Ethernet (half-duplex).
  - CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance) – used in wireless LANs (Wi-Fi).
- This ensures collision handling, fairness, and efficient usage of the physical medium.
    
b. MAC Addressing:
- The MAC layer uses 48-bit MAC addresses, assigned by the manufacturer (burned into NIC EEPROM), for identifying devices uniquely in a LAN.
- Format (in hexadecimal): 00:1A:2B:3C:4D:5E.
    
c. Frame Construction and Delimiting:
- MAC constructs data frames by encapsulating network layer packets (e.g., IPv4/IPv6 packets) into MAC frames.
- MAC frame components:
  - Preamble: For synchronization.
  - Destination MAC address
  - Source MAC address
  - Type/Length field
  - Payload (data from network layer)
  - FCS (Frame Check Sequence)
  
d. Error Detection:
- The MAC layer uses CRC (Cyclic Redundancy Check) via the FCS field to detect transmission errors.
- It does not correct errors but drops frames with detected corruption.

e. Flow Control:
- In full-duplex Ethernet, MAC layer may support IEEE 802.3x flow control using PAUSE frames to prevent buffer overflow.

f. MAC Scheduling and QoS:
- In modern wireless networks (e.g., 802.11e), MAC also supports Quality of Service (QoS) features for traffic prioritization, such as differentiating between voice, video, and best-effort data.


## 2. Describe the frame format of the 802.11 MAC header and explain the purpose of each fields.
ans: 

| **Field**         | **Size**     | **Purpose**                                           |
|------------------|--------------|--------------------------------------------------------|
| **Frame Control** | 2 bytes      | Frame type/subtype, control flags (ToDS, Retry, etc.) |
| **Duration/ID**   | 2 bytes      | NAV time or Association ID (for PS-Poll)              |
| **Address 1**     | 6 bytes      | Receiver / Destination MAC address                    |
| **Address 2**     | 6 bytes      | Transmitter / Source MAC address                      |
| **Address 3**     | 6 bytes      | BSSID or third party address                          |
| **Sequence Control** | 2 bytes  | Sequence & Fragment number                            |
| **Frame Body**    | 0–2312 bytes | Data or control/management information                |
| **FCS**           | 4 bytes      | CRC for error detection                               |

## 3. List all the MAC Layer functionalities in all Management, Control and Data plane.
ans: 
### a. Management Plane
- Beaconing: Advertise network presence.
- Authentication/Deauthentication: Verify identity.
- Association/Reassociation: Connect and maintain link with AP.
- Probing: Discover networks.
- Synchronization: Align timing between devices.
- Capability Exchange: Share supported features.
- Mobility Support: Handle roaming between APs.
- Power Management: Allow devices to sleep and wake efficiently.

### b. Control Plane
- RTS/CTS: Avoid collisions via handshaking.
- ACK: Confirm successful frame receipt.
- NAV: Reserve the channel.
- Medium Access: Use CSMA/CA to access the channel.
- Fragmentation: Break large frames into smaller ones.
- Block ACK: Acknowledge multiple frames together.

### c. Data Plane
- Frame Transmission: Send and receive user data.
- Addressing: Use MAC addresses for delivery.
- Encryption: Secure data (e.g., WPA2).
- QoS Support: Prioritize traffic.
- Aggregation: Combine multiple frames to reduce overhead.
- Error Detection: Use FCS to detect frame errors.

## 4. Explain about the scanning process in detail.
ans: 
The scanning process in IEEE 802.11 (Wi-Fi) is how a wireless device (client or STA – Station) discovers available wireless networks (Access Points or APs) in its vicinity. It is a part of the MAC layer management functionality and is essential for association, roaming, and mobility.
Types of Scanning:
### 1. Passive Scanning

  Process:
  - STA listens for beacon frames periodically broadcasted by APs on each channel.
  - Beacon contains SSID, supported rates, capabilities, etc.

  Operation: STA switches to a channel, listens for a beacon for a specified time (dwell time), and then switches to the next.

  Pros:
  - Low power consumption, no transmission required.

  Cons:
  - Slower because it waits for beacon intervals (typically 100 ms).
  - Not all APs may be discovered if beacons are missed.

### 2. Active Scanning

  Process:
  - STA sends probe request frames on each channel.
  - APs receiving the probe respond with probe response frames.

  Operation:
  - Faster discovery — doesn’t wait for beacons.
  - STA may send probe request with a specific SSID or a null SSID (wildcard) to discover all APs.

  Pros:
  - Faster than passive scanning.

  Cons:
  - Higher power usage.
  - Generates extra traffic (can be blocked in some networks).

### Scanning Sequence (Active)
- Select channel
- Send probe request
- Wait for probe responses
- Record info (SSID, RSSI, BSSID, channel, capabilities)
- Switch to next channel and repeat.


## 5. Brief about the client association process.
ans: The association process connects a client (STA) to an Access Point (AP), allowing it to exchange data on the network.

### Steps:
**1. Scanning:**
- Client discovers APs via passive (beacons) or active (probe request/response) scanning.

**2. Authentication:**
- Initial identity check using Open System or Shared Key method.
- In modern networks, further authentication (e.g., WPA2 handshake) happens later.

**3. Association Request:**
- Client sends an Association Request frame to the selected AP.
- Includes SSID, supported rates, and security capabilities.

**4. Association Response:**
- AP replies with Association Response frame.
- Indicates success or failure and assigns an Association ID (AID) to the client.

**5. 4-Way Handshake:**
- If WPA2/WPA3 is used, a secure key exchange is performed to establish encryption.


## 6. Explain each steps involved in EAPOL-4 handshake and the purpose of each keys derived from the process.
ans : EAPOL 4-Way Handshake Steps

**Step 1:** AP to STA (Message 1)
- AP sends a nonce (ANonce) and supported WPA capabilities.
- STA now has: PMK, ANonce, and its own random SNonce.
- STA computes the PTK = PRF(PMK, ANonce, SNonce, MAC addresses)

**Step 2:** STA to AP (Message 2)
- STA sends its nonce (SNonce) + MIC (Message Integrity Code) using KCK.
- Confirms it can compute PTK using PMK.
- Also indicates readiness to receive GTK.

**Step 3:** AP to STA (Message 3)
- AP sends:
  - GTK encrypted with KEK,
  - Replay counter,
  - MIC using KCK
- Ensures secure group key sharing.

**Step 4:** STA to AP (Message 4)
- STA confirms it received GTK and completed handshake.
- Sends ACK with MIC using KCK.

## 7. Describe the power saving schemes in MAC Layer and explore on the types of Power saving mechanisms. 
ans:
Here’s a shorter overview of power saving mechanisms in the MAC layer:

**1. Active Mode (AM)**
- Device stays awake, actively transmitting and receiving.
- High power consumption.

**2. Power Save Mode (PSM)**
- Device sleeps and wakes periodically to check for data.
- AP buffers data until STA wakes up.
- Low power during sleep, higher when active.

**3. Polling Mechanism**
- STA wakes at scheduled times (from AP's beacon).
- STA sends PS Poll to get buffered data from the AP.

**4. Dynamic Power Save (DPS)**
- STA adjusts sleep/wake time based on traffic conditions.
- Efficient power saving.

**5. APSD (Automatic Power Save Delivery)**
- STA stays asleep but wakes briefly for QoS traffic (e.g., voice).
- Low power but quick wake-ups for critical traffic.

**6. U-APSD (Unscheduled APSD)**
- Flexible wake-up times for unscheduled traffic.
- More efficient power usage for non-time-sensitive data.

**7. WMM/PS (Wi-Fi Multimedia Power Save)**
- Prioritizes multimedia traffic (e.g., VoIP) while saving power.
- Ensures low latency for time-sensitive applications.

**Power Saving Process**:  
- STA sleeps -> AP buffers data -> STA wakes up -> STA requests data via PS Poll.

## 8. Describe the Medium Access Control methodologies.
ans: 

**1. CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)**
- Listen before transmit to avoid collisions.
- Backoff if channel is busy.

**2. DCF (Distributed Coordination Function)**
- CSMA/CA with random backoff.
- Fair access without central control.

**3. PCF (Point Coordination Function)**
- AP controls access by polling devices.
- Reduces collisions but less efficient.

**4. HCF (Hybrid Coordination Function)**
- Combines DCF and PCF.
- HCCA for QoS, H-DCF for contention-based access.

**5. TDMA (Time Division Multiple Access)**
- Fixed time slots for devices to transmit.
- No collisions, but may be inefficient with no data.

**6. Polling and Contention-Based Access**
- Polling: AP asks devices to send data.
- Contention-Based: Devices compete using CSMA/CA.

**7. Frame Bursting**
- Send multiple frames without waiting for an ACK after each one.
- Improves throughput by reducing overhead.


## 9. Brief about the Block ACK mechanism.
ans: The Block ACK (Acknowledgment) mechanism is used to improve efficiency in wireless networks by reducing overhead associated with individual acknowledgments for each transmitted frame.

**How It Works**
- **Group Acknowledgments**: Instead of acknowledging each individual frame, a single Block ACK is sent to acknowledge multiple frames at once.
- **Window-Based**: Frames are sent in a window of sequential frames. The receiver can acknowledge all frames within the window at once, reducing the number of ACK frames sent.
- **Frame Sequence Numbering**: Each frame is assigned a sequence number. The Block ACK covers multiple frames with consecutive sequence numbers.

**Key Components**
1. **Block ACK Request (BAR)**: Sent by the receiver to request a Block ACK from the sender.
2. **Block ACK (BA)**: Sent by the sender to acknowledge the receipt of multiple frames.

**Advantages**
- **Reduced Overhead**: Fewer ACK frames result in less control traffic and better throughput.
- **Improved Efficiency**: Particularly useful in high-speed networks with large data transfers.


## 10. Explain about A-MSDU, A-MPDU and A-MSDU in A-MPDU.
ans: 
These are different methods used to improve the efficiency of data transmission in Wi-Fi networks by aggregating multiple frames into a single transmission. Here's an explanation of each:

**1. A-MSDU (Aggregate MAC Service Data Unit)**
- Description: Combines multiple MSDUs (MAC Service Data Units) into a single frame.
- Structure: A single frame contains multiple payloads, each corresponding to an individual MSDU.
- Key Features:
  - Single PHY transmission for multiple data frames.
  - Reduced overhead by sharing the header.
- Limitations:
  - Limited by the frame size (typically 8K bytes max).
  - Error recovery is difficult, as a single error in the frame affects all MSDUs.

**2. A-MPDU (Aggregate MAC Protocol Data Unit)**
- Description: Aggregates multiple MPDUs (MAC Protocol Data Units) into a single transmission.
- Structure: Multiple MPDUs are sent in a single frame, each with its own header and payload.
- Key Features:
  - Higher throughput than A-MSDU by allowing more independent frames.
  - Error recovery is easier because errors affect only individual MPDUs, not the entire transmission.
- Limitations: Higher overhead compared to A-MSDU due to multiple headers.

**3. A-MSDU in A-MPDU**
- Description: Combines the features of A-MSDU and A-MPDU, where multiple A-MSDUs are aggregated into a single A-MPDU.
- Structure: An A-MPDU contains multiple A-MSDUs, each of which holds multiple MSDUs.
- Key Features:
  - Combines header reduction from A-MSDU with the error tolerance of A-MPDU.
  - Optimal for networks requiring high efficiency and throughput.
