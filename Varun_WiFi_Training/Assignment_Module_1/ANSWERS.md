## 1. In which OSI layer the WiFi standard /protocol fits ?

WiFi, based on the IEEE 802.11 standard, operates primarily at the Physical Layer (Layer 1) and the Data Link Layer (Layer 2) of the OSI model.

### a. At the Physical Layer, WiFi handles the actual transmission of data as radio waves. ###
- It defines the frequencies used for communication, such as 2.4 GHz, 5 GHz, and 6 GHz, and determines how data is modulated and encoded for wireless transmission.
- Different modulation techniques like OFDM (Orthogonal Frequency Division Multiplexing) and DSSS (Direct Sequence Spread Spectrum) ensure efficient data transfer while minimizing interference.
- The Physical Layer also governs transmission power, signal strength, and how devices detect and decode incoming signals.

### b. At the Data Link Layer, WiFi ensures reliable data delivery between devices. ###
- It is responsible for MAC (Media Access Control) addressing, which uniquely identifies devices in a network.
- Since multiple devices share the same wireless medium, WiFi employs CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance) to manage access and prevent data collisions.
- This layer also handles frame formatting, error detection, and retransmission if necessary.
- Additionally, security protocols such as WPA2 and WPA3 operate at this layer to encrypt and protect wireless communication.

Unlike wired Ethernet, which uses cables for transmission, WiFi allows data to be transmitted over the air.
However, it does not assign IP addresses or route data between networks, as these functions belong to the Network Layer (Layer 3). Instead, WiFi provides the underlying infrastructure for wireless communication by enabling data transmission at Layers 1 and 2.



## 2. Can you share the Wi-Fi devices used everyday, share that device's wireless capability after connecting to the network. Match the device corresponding to WiFi Generations based on properties ##

(i) PC / Laptop

- The device supports 2.4 GHz and 5 GHz frequencies.
- The connection speed is 60 Mbps on 2.5 GHz.
- The security standard is WPA/WPA2.
- It supports Wi-Fi 4 (802.11n) or Wi-Fi 5 (802.11ac).

![Image](https://github.com/user-attachments/assets/22761471-0ee2-4133-b41e-5efa727302ae)

(ii) Mobile

- The Wi-Fi type is explicitly listed as Wi-Fi 4 (802.11n).
- The transmit link speed is 270 Mbps, and the receive link speed is 243 Mbps.
- The frequency band is both 2.4 GHz and 5 GHz.

The MAC address is randomized, which is common in modern Wi-Fi standards for privacy.

![Image](https://github.com/user-attachments/assets/192c3e21-d254-4d42-88e4-a3c94827299d)


## 3. What is BSS and ESS ?

BSS (Basic Service Set) and ESS (Extended Service Set) are key Wi-Fi network architectures.  

- A BSS is the fundamental building block of a Wi-Fi network, consisting of a single access point (AP) and the connected wireless devices (stations). Each BSS is identified by a unique BSSID (Basic Service Set Identifier), which is typically the MAC address of the AP. BSS can be infrastructure mode (with an AP) or independent mode (ad-hoc, without an AP).
- An ESS is a collection of multiple BSSs connected through a common wired network, allowing seamless roaming between APs. It enables larger Wi-Fi coverage, such as in offices or campuses, and is identified by an SSID (Service Set Identifier), which remains the same across APs for smooth handoff.

In short, BSS is a single Wi-Fi network with one AP, while ESS is a group of BSSs forming a larger, unified network.


## 4. What are the basic functionalities of Wi-Fi Accesspoints ?

A **Wi-Fi Access Point (AP)** serves as a central hub for wireless communication, enabling devices to connect to a wired network via Wi-Fi. Its basic functionalities include:  

1. **Wireless Signal Transmission & Reception** – Converts wired network data into wireless signals and vice versa, allowing devices to communicate wirelessly.  

2. **Network Bridging** – Acts as a bridge between wired and wireless networks, enabling Wi-Fi-enabled devices to access the internet or local network resources.  

3. **MAC Address Filtering** – Controls access by allowing or blocking devices based on their MAC addresses.  

4. **Security & Encryption** – Implements security protocols like WPA2/WPA3 to protect wireless communications from unauthorized access.  

5. **DHCP & IP Address Assignment** – Assigns IP addresses to connected devices if configured as a DHCP server or relays requests to a router.  

6. **Bandwidth Management** – Regulates network traffic and prioritizes bandwidth for specific applications or users.  

7. **Roaming Support** – In an ESS, facilitates seamless handoff between APs for uninterrupted connectivity.


## 5. Difference between Bridge Mode and Repeater Mode 

| Feature          | **Bridge Mode** | **Repeater Mode** |
|-----------------|---------------|----------------|
| **Purpose** | Connects two separate networks (wired or wireless) to extend connectivity. | Extends the existing Wi-Fi network by amplifying the signal. |
| **Network Type** | Works between different network segments. | Works within the same network. |
| **IP Address** | Devices connected to the bridge may get a different subnet. | Devices stay in the same subnet as the main network. |
| **Data Handling** | Forwards network traffic between two networks. | Duplicates and relays Wi-Fi signals to extend coverage. |
| **Performance** | More efficient; does not reduce bandwidth. | May reduce bandwidth due to retransmission. |
| **Use Case** | Connecting two LANs, wired-to-wireless bridging. | Extending Wi-Fi range in large homes or offices. |


## 6. What are the differences between 802.11a and 802.11b

| Feature       | **802.11a** | **802.11b** |
|--------------|------------|------------|
| **Frequency Band** | 5 GHz | 2.4 GHz |
| **Maximum Speed** | 54 Mbps | 11 Mbps |
| **Range** | Shorter (due to higher frequency) | Longer (due to lower frequency) |
| **Interference** | Less interference (5 GHz is less crowded) | More interference (shares 2.4 GHz with other devices like microwaves, Bluetooth) |
| **Channel Availability** | More channels, reducing congestion | Fewer channels, more congestion |
| **Cost** | Higher cost due to advanced technology | Lower cost, more widely used in early Wi-Fi devices |
| **Adoption** | Mainly used in enterprise setups | Common in consumer-grade networks during the early 2000s |

## 7. Configure the modem/hotspot to operate only in 2.4GHz and connect device and capture the capability in your device. Repeat the same in 5GHz and tabulate all the differences 

My modem only supports single-band : 2.4 GHz

The observations in general between 2.4 GHz and 5GHz is 

| Feature          | 2.4 GHz | 5 GHz |
|-----------------|--------|-------|
| **Speed**       | Slower (max ~600 Mbps) | Faster (up to ~9.6 Gbps with Wi-Fi 6) |
| **Range**       | Longer (better wall penetration) | Shorter (weaker through walls) |
| **Interference** | More interference (used by microwaves, Bluetooth, etc.) | Less interference (fewer competing devices) |
| **Latency**     | Higher latency | Lower latency (better for gaming/streaming) |
| **Bandwidth**   | Narrower channels (20/40 MHz) | Wider channels (up to 160 MHz) |
| **Device Compatibility** | Supported by almost all devices | Only newer devices support it |


## 8. What is the difference between IEEE and WFA

IEEE (Institute of Electrical and Electronics Engineers) and WFA (Wi-Fi Alliance) are both organizations that play significant roles in technology and wireless networking, but they have different focuses and responsibilities.

1. IEEE (Institute of Electrical and Electronics Engineers)
- Type: Professional organization and standards body.
- Role: Develops technical standards across multiple industries, including computing, telecommunications, power, and aerospace.
- Key Wireless Standards: IEEE 802.11 (the set of standards for Wi-Fi).
- Scope: Broader than just Wi-Fi; covers numerous engineering and technology fields.

2. WFA (Wi-Fi Alliance)
- Type: Industry consortium.
- Role: Promotes Wi-Fi technology, ensures interoperability, and certifies devices that comply with IEEE 802.11 standards.
- Key Activities: 
  - Certifies Wi-Fi products for interoperability.
  - Develops enhancements and branding (e.g., Wi-Fi 6, Wi-Fi 7).
  - Advocates for Wi-Fi adoption globally.
- Scope: Focused specifically on Wi-Fi and wireless networking.

| Feature            | IEEE                            | WFA                             |
|-------------------|--------------------------------|--------------------------------|
| **Type**          | Standards Development Body    | Industry Alliance              |
| **Focus**         | Engineering and technology standards | Wi-Fi technology and interoperability |
| **Role**          | Develops IEEE 802.11 standards | Certifies Wi-Fi products for compatibility |
| **Key Contribution** | Defines how Wi-Fi works (protocols, speeds, etc.) | Ensures Wi-Fi devices work together properly |
| **Scope**         | Broad (includes power, telecom, computing, etc.) | Narrow (Wi-Fi and wireless networking) |

## 9. List down the type of Wi-Fi internet connectivity backhaul , share your home/college's wireless internet connectivity backhaul name and its properties.

Types of Wi-Fi Internet Connectivity Backhaul
Wi-Fi networks use backhaul connections to link access points (APs) to the internet or a central network. Backhaul can be wired or wireless and is essential for reliable connectivity.

- Wired Backhaul
  - Fiber Optic – High-speed, low-latency connection; best for high-performance networks.
  - Ethernet (Copper) – Stable and widely used; supports speeds up to 10 Gbps.
  - Coaxial (Cable Internet) – Used for broadband via cable TV providers; slower than fiber.
  - DSL (Digital Subscriber Line) – Uses phone lines; lower speeds (1–100 Mbps).

- Wireless Backhaul
  - Microwave Links – Point-to-point wireless transmission for remote areas.
  - Cellular (4G/5G) – Used in mobile hotspots or fixed wireless access (FWA).
  - Satellite (e.g., Starlink) – Used in remote locations, but higher latency.
  - Wi-Fi Mesh or Point-to-Point Wi-Fi – Uses Wi-Fi signals for backhaul between nodes.

## 10. List down the Wi-Fi topologies and use cases of each one. 

**1. Infrastructure Mode (Basic Service Set - BSS)**  
- Uses an **Access Point (AP)** to connect devices to a wired network.  
- Each AP forms a **Basic Service Set (BSS)** with connected devices.  

**Use Cases:**  
- Home Wi-Fi networks.  
- Office networks with centralized management.  
- Public Wi-Fi hotspots in cafes, airports, and hotels.  

**2. Extended Service Set (ESS)**  
- Multiple **Access Points (APs)** are interconnected via **wired or wireless backhaul**.  
- Devices can roam between APs using the same **SSID** (Wi-Fi network name).  

**Use Cases:**  
- Large homes and multi-story buildings.  
- Corporate and campus networks for seamless connectivity.  
- Hospitals, universities, and large facilities needing continuous coverage.  

**3. Ad-Hoc Mode (Independent Basic Service Set - IBSS)**  
- Devices communicate directly without an access point.  
- Peer-to-peer (P2P) Wi-Fi communication.  

**Use Cases:**  
- Quick file sharing between laptops or mobile devices.  
- Emergency networks in disaster recovery scenarios.  
- Military and tactical networks for secure, flexible communication.  

**4. Mesh Wi-Fi (Wireless Mesh Network - WMN)**  
- Multiple APs (mesh nodes) communicate wirelessly to provide seamless coverage.  
- Uses a combination of wired and wireless backhaul.  
- Devices automatically connect to the best available node.  

**Use Cases:**  
- Smart homes and IoT networks.  
- Large venues like hotels, malls, and stadiums.  
- Rural and remote areas where wired infrastructure is limited.  

**5. Wi-Fi Direct**  
- Allows two devices to connect **directly** without an access point.  
- Functions similarly to Bluetooth but with higher speed and range.  

**Use Cases:**  
- Wireless printing and file sharing.  
- Gaming console connectivity.  
- IoT device pairing and communication.  
