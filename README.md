# Lab Work Synthesis – TFTP Client
### Jade Piller and Letícia Moreira

## Introduction
This project aims to develop a Trivial File Transfer Protocol (TFTP) client adhering to RFC specifications and utilizing Wireshark captures for validation. TFTP is commonly employed for network installations, diskless node operations, and firmware updates in networking equipment.

## Table of Contents

# Considerations
## Difficulties Encountered

1. **Command-Line Argument Handling:** Implementing proper handling of command-line arguments for the gettftp  program presented challenges, especially in extracting and validating server and file information.

2. **Troubles Understanding and using the right protocol:** Though TFTP is a simple file transfer protocol? ensuring we were adhering to the right specifications was challenging and we found ourselves stuck on a DNS protocol displayed in wireshark instead.

3. **Deciphering Packet Details:** Wireshark provides detailed information about each packet and understanding how to interpret this information required some effort.

4. **Building TFTP Packets:** We had some troubles at first to construct a well-formed Read Request and to handle different types of TFTP packets including Data, Acknowledgement and Error packets.

5. **Socket connections:** We spent some time understanding how to manage the socket connections as well as ensuring proper error handling. 

6. **Debugging Code Execution:** Troubleshooting issues related to code execution and identifying potential errors during runtime was a challenge. This involved debugging the code to pinpoint any issues.

## What was Learned?
1. **Protocol Specifications Understanding:** A deep understanding of TFTP protocol specifications (RFCs) is crucial for accurate implementation. 

2. **Effective Communication with Professor:** Regular communication with the professor at checkpoints was essential to validate progress, seek clarification on ambiguities, and ensure the correct direction of implementation.

3. **Building TFTP Packets** We learned how to handle different types of TFTP packets including Data, Acknowledgement and Error packets.

4. **Wireshark Usage:** Analyzing Wireshark captures provided valuable insights into the communication patterns and protocol adherence.

5. **Gradual Implementation:** Implementing features in a step-by-step manner, starting from command-line parsing to protocol-specific actions, allowed for systematic troubleshooting and debugging.

6. **Error Handling Importance:** Effective error-handling mechanisms are crucial in a network application to handle unexpected situations gracefully and prevent unintended consequences.

7. **Real-World Application:** Understanding the practical applications of TFTP, such as network installations and firmware updates, reinforced the significance of reliable file transfer mechanisms in networking scenarios.

## Colaborators
<table>
  <tr>
      <td align="center">
      <a href="#">
        <img src="https://github.com/jadep1103/synthesysjade/assets/72623771/8ba95fc6-6138-4b4e-a3c4-d038aab38c1a" width="200px;" alt="Foto Jade"/><br>
        <sub>
          <b>Jade Piller--Cammal</b>
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
