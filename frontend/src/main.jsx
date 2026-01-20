import React from "react";
import { createRoot } from "react-dom/client";
import "./styles/app.css";

const root = createRoot(document.getElementById("root"));

root.render(
  <React.StrictMode>
    <div>
      <h1>Gamely</h1>
      <p>Gamely is a multi-game platform. Monopoly is the first game.</p>
      <p>React renders UI only. Game logic lives on the server.</p>
    </div>
  </React.StrictMode>
);
