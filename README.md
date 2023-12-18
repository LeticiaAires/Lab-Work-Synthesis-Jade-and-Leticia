# Lab Work Synthesis – TFTP Client
### Jade Piller and Letícia Moreira

## Introduction
This project aims to develop a Trivial File Transfer Protocol (TFTP) client adhering to RFC specifications and utilizing Wireshark captures for validation. TFTP is commonly employed for network installations, diskless node operations, and firmware updates in networking equipment.

## Table of Contents

# Considerations
## Difficulties Encountered
1. **Command-Line Argument Handling:** Implementing proper handling of command-line arguments for the gettftp and puttftp programs presented challenges, especially in extracting and validating server and file information.

2. **Socket Programming:** Establishing a connection socket to the server required careful handling, and errors in socket programming could lead to connection issues.

3. **TFTP Protocol Implementation:** Adhering to the RFC specifications for TFTP (RFC1350, RFC2347, RFC2348, RFC2349, RFC7440) posed difficulties, especially in correctly forming Read Request (RRQ) and Write Request (WRQ) packets.

4. **Data Packet and Acknowledgment Handling:** Implementing reliable mechanisms for receiving single and multiple Data (DAT) packets along with their acknowledgments (ACK) demanded attention to detail, as errors could lead to file transfer failures.

5. **Error Handling:** Dealing with potential errors, timeouts, and ensuring graceful termination in case of unexpected issues required robust error-handling mechanisms.


## What was Learned?
1. **Protocol Specifications Understanding:** A deep understanding of TFTP protocol specifications (RFCs) is crucial for accurate implementation. Referencing the RFC documents is essential for protocol compliance.

2. **Effective Communication with Professor:** Regular communication with the professor at checkpoints was essential to validate progress, seek clarification on ambiguities, and ensure the correct direction of implementation.

3. **Testing Strategies:** Utilizing various testing options, including local TFTP servers, netcat, and external TFTP servers, helped validate the client's functionality and compatibility.

4. **Wireshark Usage:** Analyzing Wireshark captures, both self-generated and available online, provided valuable insights into the communication patterns and protocol adherence.

5. **Gradual Implementation:** Implementing features in a step-by-step manner, starting from command-line parsing to protocol-specific actions, allowed for systematic troubleshooting and debugging.

6. **Error Handling Importance:** Robust error-handling mechanisms are crucial in a network application to handle unexpected situations gracefully and prevent unintended consequences.

7. **Real-World Application:** Understanding the practical applications of TFTP, such as network installations and firmware updates, reinforced the significance of reliable file transfer mechanisms in networking scenarios.

## Colaborators
<table>
  <tr>
      <td align="center">
      <a href="#">
        <img src="https://github.com/jadep1103/synthesysjade/assets/72623771/8ba95fc6-6138-4b4e-a3c4-d038aab38c1a" width="200px;" alt="Foto Jade"/><br>
        <sub>
          <b>Jade Piller</b>
          </p>jadep1103
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/72623771?v=4" width="200px;" alt="Foto Letícia Aires"/><br>
        <sub>
          <b>Letícia Aires</b>
          </p>LeticiaAires
        </sub>
      </a>
    </td>
